#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>
#include <iostream>

using namespace std;

struct MemoryBlock {
    int startAddress;
    int size;
    bool isFree;
};

class MemoryManager {
private:
    int totalMemorySize;
    vector<MemoryBlock> memoryMap;

public:
    MemoryManager(int totalSize) : totalMemorySize(totalSize) {
        memoryMap.push_back({0, totalSize, true});
    }

    int allocate(int size) {
        for (auto it = memoryMap.begin(); it != memoryMap.end(); ++it) {
            if (it->isFree && it->size >= size) {
                int start = it->startAddress;
                it->isFree = false;
                
                if (it->size > size) {
                    MemoryBlock newBlock = {start + size, it->size - size, true};
                    it->size = size;
                    //Insert the new free block after the current one
                    memoryMap.insert(it + 1, newBlock);
                }
                cout << "Allocated " << size << " bytes at address " << start << endl;
                return start;
            }
        }
        cout << "Error: Not enough memory to allocate " << size << " bytes." << endl;
        return -1; //Indicates allocation failure
    }

    void deallocate(int startAddress) {
        for (auto& block : memoryMap) {
            if (block.startAddress == startAddress) {
                block.isFree = true;
                cout << "Deallocated memory at address " << startAddress << endl;
                //Optional: Merge with adjacent free blocks (coalescing)
                //This can be added later for more advanced memory management.
                return;
            }
        }
    }
     void printMemoryMap() const {
        cout << "--- Memory Map ---" << endl;
        for (const auto& block : memoryMap) {
            cout << "Address: " << block.startAddress << ", Size: " << block.size
                 << ", Status: " << (block.isFree ? "Free" : "Allocated") << endl;
        }
        cout << "------------------" << endl;
    }
};

bool operator==(const MemoryBlock& a, const MemoryBlock& b) {
    return a.startAddress == b.startAddress && a.size == b.size && a.isFree == b.isFree;
}


#endif 