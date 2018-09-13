// Copyright (c) 2018 Jason Graalum
//
// 
// MemList.cpp
//
// // Class implementation of MemList for New Beginnings Final Proficiency Exam
// 2018
//!!!!!!!!!!!!!!!!63: level 1

#include "MemList.hpp"
#include "MemBlock.hpp"
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////
// Level 0 Methods
/////////////////////////////////////////////////////////////////////////////////
// Default constructor which creates empty lists for both the Free and Reserved
// lists
//
// Level 0
//
MemList::MemList()
{
    free_head = NULL;
    reserved_head = NULL;
}
// Display the Free List
//
// Level 0
//
void MemList::displayFree() 
{
    std::cout << "Free Memory" << std::endl;
    MemBlock * current = free_head;
    free_head->printBlockInfoHeader();
    int count = 0;
    while(current) {
        current->printBlockInfo(count);
        current = current->getNext();
        count++;
    }
    std::cout << std::endl;
}

// Display the Reserved List
//
// Level 0
//
void MemList::displayReserved() 
{
    std::cout << "Reserved Memory" << std::endl;
    MemBlock * current = reserved_head;
    reserved_head->printBlockInfoHeader();

    int count = 0;
    while(current) {
        current->printBlockInfo(count);
        current = current->getNext();
        count++;
    }
    std::cout << std::endl;

}
/////////////////////////////////////////////////////////////////////////////////
// Level 1 Methods
/////////////////////////////////////////////////////////////////////////////////
// Parameterized constructor which create two lists of MemBlock 
// The Free List will contain a single MemBlock with all the memory(start_addr and mem_size)
// The Reserved List will be empty
//
// MemList = new MemList(start_addr, mem_size);
//
// Level 1
//
MemList::MemList(unsigned int s_addr, unsigned int block_size)
{
    /*
    // To be implemented(replace the two lines below)
    free_head = NULL;
    reserved_head = NULL;
    */

    //adding below:
    MemBlock *current;
    current = new MemBlock;
    current->setAddr(s_addr);
    current->setSize(block_size);
    current->setNext(NULL);
    free_head = current;

    reserved_head = NULL;
}

// Find the first MemBlock in the Free list which greater than or equal to the amount requested(via 
// the function argument). Update the MemBlock in the Free List - change the start_addr and mem_size
// by the amount of memory being reserved.
// Add the newly reserved memory into a new MemBlock in the Reserved List
// If no MemBlock in the Free List is large enough return NULL, otherwise return a pointer to 
// the new MemBlock in the Reserved List.
//
// Level 1
//
MemBlock * MemList::reserveMemBlock(unsigned int block_size)
{
    /*
    // To be implemented
    return NULL;
    */

    //adding below:
    //we want to cycle through free to find a node where size is big enough to take out block size
    //then add that block to reserved
    //then take it away from free
    
    MemBlock *current;
    current = new MemBlock;
    current = free_head;
    while ((current->getSize() < block_size) && (current->getNext() != NULL)) {
        current = current->getNext();
    }
    if (current->getSize() < block_size) {
        return NULL;
    }
    else {
        MemBlock *temp;
        temp = new MemBlock;

        temp->setAddr(current->getAddr());
        temp->setSize(block_size);
        temp->setNext(reserved_head);
        reserved_head = temp;

        unsigned int new_addr = current->getAddr() + block_size;
        unsigned int new_size = current->getSize() - block_size;
        current->setAddr(new_addr);
        current->setSize(new_size);

        return reserved_head;
    }
}


// Return the total size of all blocks in the Reserved List
//
// Level 1
//
unsigned int MemList::reservedSize()
{
    /*
    // To be implemented
    return 0;
    */

    //adding below:
    MemBlock *temp;
    temp = new MemBlock;
    temp = reserved_head;
    unsigned int total_size = 0;

    while (temp != NULL) {
        total_size += temp->getSize();
        temp = temp->getNext();
    }
    return total_size;
}

// Return the total size of all blocks in the Free List
//
// Level 1
unsigned int MemList::freeSize()
{
    /*
    // To be implemented
    return 0;
    */

    //adding below:
    MemBlock *current;
    current = new MemBlock;
    current = free_head;
    unsigned int total_size = 0;

    while (current != NULL) {
        total_size += current->getSize();
        current = current->getNext();
    }
    return total_size;
}

/////////////////////////////////////////////////////////////////////////////////
// Level 2 Methods
/////////////////////////////////////////////////////////////////////////////////
// Removes the MemBlock provided(via the pointer) from the Reserved List and adds it
// back into the Free List - it must be added back "in order of starting address".
//
// (Challenge) If the MemBlock to be freed does exist or it is a bad block(it overlaps 
// with a block in the Free list), return false.  Otherwise return true.
//
// Level 2
//
bool MemList::freeMemBlock(MemBlock * block_to_free)
{
    // To be implemented
    return false;
}



// Return a pointer to the MemBlcok with the largest size from the Free List
//
// Level 2
//
MemBlock * MemList::maxFree() 
{
    // To be implemented
    return NULL;
}

// Return a pointer to the MemBlcok with the smallest size from the Free List
//
// Level 2
//
MemBlock * MemList::minFree()
{
    // To be implemented
    return NULL;
}

// Return the number of MemBlocks in the Free List
//
// Level 2
//
unsigned int MemList::freeBlockCount()
{
    // To be implemented
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Level 3 Methods
/////////////////////////////////////////////////////////////////////////////////
// Iterate through the Free List - combine any blocks that are adjacent
// Return the number of MemBlocks removed
//
// Level 3
//
unsigned int MemList::defragFree()
{
    // To be implemented
    return 0;
}

// Return the start address of the smallest block that fits the size requested
// Ex:  MemList_Obj->minMax(100);  // Return the address of the smallest block 
//                                    that is greater than 100
// The return values are the same as in the "reserveMemBlock" member function.
//
// Level 3
//
MemBlock * MemList::reserveMinMemBlock(unsigned int)
{
    // To be implemented
    return NULL;
}




