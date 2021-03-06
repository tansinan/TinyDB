#ifndef __TINYDB_INDEX_H__
#define __TINYDB_INDEX_H__

#include <string>
#include <list>
#include <boost/filesystem.hpp>

class Database;
class ASTNodeBase;
class AbstractStorageArea;
class AbstractFixedAllocator;
class RecordAllocator;
class AbstractDynamicAllocator;
class CachedStorageArea;
class ASTCreateTableStmtNode;
class FieldList;
class FieldType;
class ASTSQLDataValue;
class ASTExpression;
class BPlusTree;
class FieldType;

class Index
{
protected:
    bool isOpened = false;
public:
    const std::string tableName;
    const std::string columnName;
    const Database* database;
    const boost::filesystem::path storagePath;
    const static int INDEX_ADDRESS_SIZE = 8;
protected:
    int indexFieldSize;
    int indexKeySize;
    CachedStorageArea *storageArea = nullptr;
    BPlusTree *bPlusTree = nullptr;
    FieldType *fieldType;
public:
    Index(
        Database* database, const std::string& tableName,
        const std::string& columnName,
        const boost::filesystem::path& storageFileName
    );
    bool initialize();
    bool drop();
    bool open();
    bool getIsOpened();
    bool close();
    bool onAddRecord(uint64_t recordAddress, char* recordBuffer);
    bool onDeleteRecord(uint64_t recordAddress, char* bufferRecord);
    /*bool addRecord(std::list<ASTSQLDataValue*> fields);
    bool updateRecord(const std::string& fieldName,
        const ASTExpression const* expression,
        const ASTExpression const* whereExpression);
    std::vector<uint64_t> findRecord(const ASTExpression *expression);
    bool deleteRecord(ASTExpression *expression);*/
};

#endif
