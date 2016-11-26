#ifndef __TINYDB_FIXED_LENGTH_NUMERICAL_TYPE_H__
#define __TINYDB_FIXED_LENGTH_NUMERICAL_TYPE_H__

#include "Parser/ASTNodes.h"
#include "FieldType.h"

template<class T>
class FixedLengthIntegerFieldType : public FieldType
{
public:
    virtual bool hasConstantLength() override;
    virtual int getConstantLength() override;
    virtual int parseIntegerValue(std::string& integerValue, char* buffer);
    virtual int parseStringValue(std::string& stringValue, char* buffer);
    virtual int parseASTNode(ASTNodeBase* node, char* buffer);
    virtual std::string ToStringValue(char *binaryStream, int length)
    {
        //TODO
        return "";
    }
    virtual int getHeaderLength();
    virtual void writeHeader(char *buffer);
    virtual int compare(char* buffer, ASTNodeBase* node)
    {
        //TODO
        return 0;
    }
    virtual int getDataLength(ASTNodeBase* node)
    {
        //TODO
        return 0;
    }
    virtual int toBinary(ASTNodeBase *node, char* buffer)
    {
        //TODO
        return 0;
    }
    virtual int parseHeader(char* buffer)
    {
        //TODO
        return 0;
    }
};


template<class T>
bool FixedLengthIntegerFieldType<T>::hasConstantLength()
{
    return true;
}

template<class T>
int FixedLengthIntegerFieldType<T>::getConstantLength()
{
    return sizeof(T);
}

template<class T>
int FixedLengthIntegerFieldType<T>::parseIntegerValue(std::string& integerValue, char* buffer)
{
    //TODO: Handle integer type with different width!
    T data = (T)std::stoll(integerValue.c_str());
    *(T*)buffer = data;
    return sizeof(T);
}

template<class T>
int FixedLengthIntegerFieldType<T>::parseStringValue(std::string& stringValue, char* buffer)
{
    //TODO: Handle integer type with different width!
    //TODO: Does SQL allow this?
    T data = (T)std::stoll(stringValue.c_str());
    *(T*)buffer = data;
    return sizeof(T);
}

template<class T>
int FixedLengthIntegerFieldType<T>::parseASTNode(ASTNodeBase* node, char* buffer)
{
    auto valueNode = dynamic_cast<ASTSQLDataValue*>(node);
    if (valueNode == nullptr)
    {
        return -1;
    }
    T data = (T)std::stoll(valueNode->value.c_str());
    *(T*)buffer = data;
    return sizeof(T);
}

template<class T>
int FixedLengthIntegerFieldType<T>::getHeaderLength()
{
    return 0;
}

template<class T>
void FixedLengthIntegerFieldType<T>::writeHeader(char *buffer)
{
}

#endif // __TINYDB_FIXED_LENGTH_NUMERICAL_TYPE_H__
