#ifndef __TINYDB_FIELD_LIST_H__
#define __TINYDB_FIELD_LIST_H__

#include <string>
#include <list>
#include <vector>

class FieldType;
class ASTNodeBase;
class ASTCreateTableFieldNode;
class AbstractDynamicAllocator;

class FieldList
{
public:
    struct CompiledField {
        std::string fieldName;
        FieldType* fieldType;
        uint32_t fieldOffset;
    };
protected:
    struct UncompiledField {
        std::string fieldName;
        std::string typeName;
        ASTNodeBase *astNode;
    };
    std::vector<UncompiledField> uncompiledFieldLists;
protected:
    std::vector<CompiledField> compiledField;
    int headerSize = 0;
    int recordFixedSize = 0;
    char *headerData = nullptr;
    void calculateFieldOffsets();
    void calculateNullBitmap();
public:
    int nullBitmapSize = 0;
    const static int FIXED_SIZE_MAX_BYTES = 32;
    FieldList();
    void addField(const std::string &fieldName, const std::string &typeName, ASTNodeBase *astNode);
    void compile();
    static FieldList* fromASTNode(std::list<ASTCreateTableFieldNode*> fieldNodes, AbstractDynamicAllocator *dynamicAllocator);
    static FieldList* fromBuffer(char *buffer, AbstractDynamicAllocator *dynamicAllocator);
    int getRecordFixedSize();
    int getHeaderSize();
    char* getHeaderData();
    const std::vector<CompiledField>& getCompiledFields();
    void printRecord(char * buffer, const std::vector<int> columnIndex);
    CompiledField& getField(const std::string &fieldName);
};

#endif // __TINYDB_FIELD_LIST_H__
