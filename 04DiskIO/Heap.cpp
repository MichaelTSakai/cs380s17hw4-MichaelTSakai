//********************************************************
// File name:  Heap.cpp
// Author:     Michael Sakai
// Date:       3/21/2017
// Class:      CS380
// Assignment: Disk Scheduling
// Purpose:    Defines header file Heap.h
//********************************************************

#include "Heap.h"

static const int ARRAY_BUFFER = 1; // the number of nodes before root

int leftNode(int i);
int rightNode(int i);
int parentNode(int i);

//********************************************************
// Constructor: Heap
//
// Description: Initialize data members.
//
// Parameters:  none
//
// Returned:    none
//		
//********************************************************
Heap::Heap()
{
  mHeapArray.push_back(nullptr);
  mSortDir = Direction::MAX;
}

//********************************************************
// Destructor: ~Heap
//
// Description: Destroys all datamember
//
// Parameters:  none
//
// Returned:    none
//		
//********************************************************
Heap::~Heap()
{

}

//********************************************************
// Function: deallocateItems
//
// Description: Destroys all the pointer in the map 
//
// Parameters:  none
//
// Returned:    none
//		
//********************************************************
void Heap::deallocateItems()
{
  std::vector<HNode*>::iterator iterator;

  iterator = mHeapArray.begin();

	iterator++;

  while (iterator != mHeapArray.end())
  {
    delete *iterator;
    iterator++;
  }

  mHeapArray.clear();
}

//********************************************************
// Function: insert
//
// Description: Function to insert a new node into the heap 
//              and maintain the heap property 
//
// Parameters:  pcNode - the node that is to be inserted
//
// Returned:    none
//		
//********************************************************
void Heap::insert(HNode  *pcNode)
{
  mHeapArray.push_back(pcNode);
  heapIncreaseKey(static_cast<int>(mHeapArray.size() - ARRAY_BUFFER), 
                                   pcNode);
}

//********************************************************
// Function: size
//
// Description: Return the size of the array
//
// Parameters:  none
//
// Returned:    size of the array
//		
//********************************************************
int Heap::size()
{
  return static_cast<int>(mHeapArray.size());
}

//********************************************************
// Function: getSortDirection
//
// Description: Returns the current sort direction
//
// Parameters:  none
//
// Returned:    mSortDir - the current sort direction
//		
//********************************************************
Heap::Direction Heap::getSortDirection()
{
  return mSortDir;
}

//********************************************************
// Function: setSortDirection
//
// Description: Sets the sort direction 
//
// Parameters:  dir - the new sort direction
//
// Returned:    none
//		
//********************************************************
void Heap::setSortDirection(Heap::Direction dir)
{
  mSortDir = dir;
}

//********************************************************
// Function: buildHeap
//
// Description: Builds a heap using the current array.
//
// Parameters:  none
//
// Returned:    none
//		
//********************************************************
void Heap::buildHeap()
{
  for (size_t i = mHeapArray.size() / 2; i > 0; i--)
  {
    heapify(static_cast<int>(i));
  }
}

//********************************************************
// Function: heapify
//
// Description: Maintains the heap property starting from
//              from the given index
//
// Parameters:  index - starting index to heapify
//
// Returned:    none
//		
//********************************************************
void Heap::heapify(int index)
{
  int left = leftNode(index);
  int right = rightNode(index);
  int largest = index;
  size_t heapSize = mHeapArray.size() - ARRAY_BUFFER;

  if (heapSize >= left)
  {
    if (needSwap(mHeapArray.at(index), mHeapArray.at(left)))
    {
      largest = left;
    }
  }
  if(heapSize >= right)
  {
    if (needSwap(mHeapArray.at(largest), mHeapArray.at(right)))
    {
      largest = right;
    }
  }

  if (largest != index)
  {
    std::iter_swap(&mHeapArray.at(index), &mHeapArray.at(largest));
    heapify(largest);
  }
}

//********************************************************
// Function: heapExtract
//
// Description: Extracts the root of the heap
//
// Parameters:  none
//
// Returned:    pRoot - pointer to the root of the heap
//		
//********************************************************
HNode* Heap::heapExtract()
{
  size_t size = mHeapArray.size() - ARRAY_BUFFER;
  HNode *pRoot = nullptr;

  if (mHeapArray.size() > ARRAY_BUFFER)
  {
    pRoot = mHeapArray.at(ARRAY_BUFFER);
    mHeapArray.at(ARRAY_BUFFER) = mHeapArray[size];
    mHeapArray.pop_back();

    heapify(ARRAY_BUFFER);
  }

  return pRoot;
}

//********************************************************
// Function: heapExtreme
//
// Description: Returns the root of the heap
//
// Parameters:  none
//
// Returned:    pointer to the root of the heap
//		
//********************************************************
const HNode  * Heap::heapExtreme() const
{
  return mHeapArray.at(ARRAY_BUFFER);
}

//********************************************************
// Function: heapIncreaseKey
//
// Description: increases the key at the given index location
//
// Parameters:  size  - current index of pNode
//              pNode - the replacement node that contains
//                      the increased value
//
// Returned:    none
//		
//********************************************************
void Heap::heapIncreaseKey(int size, HNode *pNode)
{
  if (*pNode < *mHeapArray.at(size))
  {
    std::cerr << "Error: key smaller than previous" << std::endl;
  }
  else
  {
    mHeapArray.at(size) = pNode; 
    while (size > ARRAY_BUFFER && needSwap(mHeapArray[parentNode(size)],
                                           mHeapArray[size]))
    {
      std::iter_swap(&mHeapArray.at(parentNode(size)), &mHeapArray.at(size));
      size = parentNode(size);
    }
  }
}

//********************************************************
// Function: updateEachKey
//
// Description: Uses pData to update each key in array
//
// Parameters:  pData - data passed into the update functions
//							size	- size of data
//
// Returned:    false if error
//		
//********************************************************
bool Heap::updateEachKey(void *pData, int size)
{
  mcVisitor = new UpdateVisitor(pData, size);
  std::vector<HNode*>::iterator iterator;

  iterator = mHeapArray.begin();

	iterator++;
  
  while (iterator != mHeapArray.end())
  {
    (*iterator)->acceptVisitor(mcVisitor);
    iterator++;
  }

  delete mcVisitor;

  return true;
}

//********************************************************
// Function: needSwap
//
// Description: Based on the current sort direction, determine
//              if the two items needs to be swapped
//
// Parameters:  pParent - left object, usually a parent
//              pChild  - right object, usually a child
//
// Returned:    bSwap - true if need swap
//		
//********************************************************
bool Heap::needSwap(const ComparableItem *pParent, const ComparableItem *pChild)
{
  bool bSwap = false;
  switch (mSortDir)
  {
  case Direction::MAX: bSwap = *pParent < *pChild;
    break;
  case Direction::MIN: bSwap = *pParent > *pChild;
    break;
  }

  return bSwap;
}

//********************************************************
// Function: operator<<
//
// Description: calls the operator<< on each items in the heap
//
// Parameters:  os      - the ostream where the output will be sent
//              theHeap - Heap object where the output will come from
//
// Returned:    os - updated ostream
//		
//********************************************************
std::ostream& operator<<(std::ostream &os, const Heap &theHeap)
{
  for (int i = 1; i < theHeap.mHeapArray.size(); i++)
  {
    os << *theHeap.mHeapArray.at(i) << " ";
  }

  return os;
}

//********************************************************
// Function: rightNode
//
// Description: returns the index of the right child
//
// Parameters:  index - the current index
//
// Returned:    the right child of the current index
//		
//********************************************************
int rightNode(int index)
{
  return index * 2 + 1;
}

//********************************************************
// Function: leftNode
//
// Description: returns the index of the left child
//
// Parameters:  index - the current index
//
// Returned:    the left child of the current index
//		
//********************************************************
int leftNode(int index)
{
  return index * 2;
}

//********************************************************
// Function: parentNode
//
// Description: returns the index of the parent
//
// Parameters:  index - the current index
//
// Returned:    the parent of the current index
//		
//********************************************************
int parentNode(int index)
{
  return index / 2;
}