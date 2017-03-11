//***************************************************************************
// File name:		HNode.h
// Author:			Shereen Khoja
// Author:			Chadd Williams
// Date:				02/16/2011
// Edited:			09/12/2013
// Class:				CS380
// Assignment:	Disk Scheduling
// Purpose:			This is the header file for the abstract Node class.
//***************************************************************************

#pragma once

#include <iostream>
#include "ComparableItem.h"

class HNode : public ComparableItem
{
public:

	// ComparableItem interface
	virtual bool operator< (ComparableItem const &right) const = 0;
	virtual bool operator> (ComparableItem  const &right) const = 0;
	virtual bool operator== (ComparableItem const  &right)const = 0;

	// Function to change the key of the HNode to the passed in argument
	// The argument is a void* since the key of the Node is dependent upon
	// the implementation

	virtual void changeKey (void*) = 0;

	// Function to output the contents of the HNode. This will be called
	// by the operator<<
	virtual void outputNode (std::ostream& os) const = 0;
	virtual ~HNode ();

	// Function to get the current key.  The user must provide an allocated
	// buffer as the first argument and the size of the buffer as the second
	// argument.  Any errors return false.
	virtual bool getKey (void*, int) const = 0;

	// this method allows the key to be changed based upon some
	// other data.  Each subclass must implement this method.
	// this might calculate a new key and then call changeKey.
	// return true on success or false on error 
	// errors include incorrect or incorrectly sized data
	// being sent to the function
	virtual bool updateKey (void*, int) = 0;

	friend std::ostream& operator<<(std::ostream &os, const HNode &theNode);
};