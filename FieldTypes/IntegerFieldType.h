#ifndef __TINYDB_INTEGER_FIELD_TYPE_H__
#define __TINYDB_INTEGER_FIELD_TYPE_H__

#include <cstdint>
#include "FixedLengthIntegerFieldType.h"

class IntegerFieldType : public FixedLengthIntegerFieldType<int32_t>
{
    virtual const std::string getTypeName() const;
    virtual FieldType* construct(ASTNodeBase *astNode, AbstractDynamicAllocator *dynamicAllocator);
    virtual FieldType* fromBinary(char *buffer, int length, AbstractDynamicAllocator *dynamicAllocator);
};

#endif // __TINYDB_INTEGER_FIELD_TYPE_H__
