//***************************************************************************
// File name:	Heap.h
// Author:		Shereen Khoja
// Author:		Chadd Williams
// Date:			02/16/2011
// Edited:		09/12/2013
// Class:			CS380
// Assignment:Disk Scheduling
// Purpose:		This is the header file for the Heap class.
//**************************************************************************

#pragma once

#include "HNode.h"
#include <vector>
#include <iostream>
#include <iomanip>

class Heap
{

public:

	// Constructor that places a null pointer at element 0 of the vector
	// This is so that the root of the heap will be located at node 1
	// and you can use the algorithms in the book
	Heap ();

	// Destructor for Heap that will NOT delete all of the HNode*'s
	// You WILL have to delete the pointers in your driver
	~Heap ();

	// convience function to deallocate the data pointed to by
	// the pointers in the heap
	void deallocateItems ();

	// Function to insert a new node into the heap and maintain
	// the heap property
	void insert (HNode  *);


	// display the heap by calling the << operator on each HNode
	friend std::ostream& operator<<(std::ostream &os, const Heap &theHeap);

	// Function to build a heap from the current vector
	void buildHeap ();


	// Function to remove the root of the heap and return it to the calling
	// function
	HNode* heapExtract ();

	// Function to return the root of the heap but NOT remove it from the heap
	const HNode  * heapExtreme () const;

	// get the size of the heap
	int size ();

	// visitor pattern (this is optional)
	// http://www.oodesign.com/visitor-pattern.html
	// This will visit each item in the heap,
	// and call HNode::updateKey(void*, int) using pData and size
	// on each of those items.
	// Lastly, buildHeap() is called.
	bool updateEachKey (void *pData, int size);

	enum Direction { MAX, MIN };

	// set the direction to sort
	void setSortDirection (Direction dir);

	// get the current sort direction
	Direction getSortDirection ();

	// Convience function to determine, based on the sort direction, 
	// if two items need to be swapped.  
	// If the sort is ASC, then true is returned if
	// pLeft is greater than pRight.
	virtual bool needSwap (const ComparableItem *pParent, const ComparableItem *pChild);

private:

	// Function to maintain the heap property starting from the given index
	void heapify (int i);

	void heapIncreaseKey (int size, HNode *pNode);

	// The heap stored as a vector of HNode*'s
	std::vector<HNode*> mHeapArray;

	Direction mSortDir;
};