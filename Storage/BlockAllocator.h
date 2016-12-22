#ifndef __TINYDB_RECORD_ALLOCATOR_H__
#define __TINYDB_RECORD_ALLOCATOR_H__

#include <cstdint>
#include "AbstractStorageArea.h"
#include "AbstractFixedAllocator.h"

class BlockAllocator : public AbstractFixedAllocator
{
//Functions related to macro block.
protected:
    //The size which one page bitmap can manage, usuallly 1GB
    uint64_t macroBlockSize;

    //The number of currently allocated macro blocks
    uint64_t allocatedMacroBlockCount;
public:

    /**
     * Get the offset of current macro block
     */
    uint64_t getMacroBlockOffset(uint64_t macroBlockIndex);

//Related to block management inside a macro block.
public:
    enum BlockStatus {
        UNUSED = 0,
        PARTIALLY_USED = 1,
        FULLY_USED = 2,
        RESERVED = 3,
    };
    int blocksPerMacroBlock;
    int blocksReservedPerMacroBlock; // First 4096 reserved
    int allocationOffset;// = blocksReservedPerMacroBlock * blockSize
    int blockStatusBitmapOffset;
    int blockSize;
protected:
    void initializeMacroBlock(uint64_t macroBlockOffset);
    bool setBlockStatus(uint64_t macroBlockOffset, uint64_t blockIndex, BlockStatus status);
public:
    BlockStatus getBlockStatus(uint64_t macroBlockOffset, uint64_t blockIndex);
    virtual uint64_t getBlockOffset(uint64_t macroBlockOffset, uint64_t blockIndex);

public:
    BlockAllocator(AbstractStorageArea* storageArea);
    //const AbstractStorageArea* getStorageArea() const;
    virtual void initialize();
    virtual uint64_t bytesTotal();
    virtual uint64_t bytesUsed();
    virtual uint64_t bytesAvailable();
    virtual AbstractStorageArea::AccessProxy allocate();
    virtual bool free(const AbstractStorageArea::AccessProxy& accessProxy);
};

#endif // __TINYDB_RECORD_ALLOCATOR_H__
