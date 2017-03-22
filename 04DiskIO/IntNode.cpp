//********************************************************
// File name:  IntNode.cpp
// Author:     Michael Sakai
// Date:       3/21/2017
// Class:      CS380
// Assignment: Disk Scheduling
// Purpose:    Defines header file IntNode.h
//********************************************************

#include "IntNode.h"

//********************************************************
// Constructor: IntNode
//
// Description: Initialize data members.
//
// Parameters:  none
//
// Returned:    none
//		
//********************************************************
IntNode::IntNode()
{

}

//********************************************************
// Constructor: IntNode
//
// Description: Initialize data members.
//
// Parameters:  key - the key of the node
//
// Returned:    none
//		
//********************************************************
IntNode::IntNode(int key)
{
  mKey = key;
}

//********************************************************
// Destructor: ~Heap
//
// Description: Destroys all data member
//
// Parameters:  none
//
// Returned:    none
//		
//********************************************************
IntNode::~IntNode() 
{
}

//********************************************************
// Function: operator<
//
// Description: overloads < operator. Compares the key 
//              of the two object
//
// Parameters:  cRight - the right object
//
// Returned:    true of left object < right object
//		
//********************************************************
bool IntNode::operator<(ComparableItem const &cRight) const
{
  return mKey < dynamic_cast<const IntNode*>(&cRight)->mKey;
}

//********************************************************
// Function: operator>
//
// Description: overloads > operator. Compares the key 
//              of the two object
//
// Parameters:  cRight - the right object
//
// Returned:    true of left object > right object
//		
//********************************************************
bool IntNode::operator>(ComparableItem const &cRight) const
{
  return mKey > dynamic_cast<const IntNode*>(&cRight)->mKey;
}

//********************************************************
// Function: operator==
//
// Description: overloads == operator. Compares the key 
//              of the two object
//
// Parameters:  cRight - the right object
//
// Returned:    true of left object == right object
//		
//********************************************************
bool IntNode::operator== (ComparableItem const  &cRight) const
{
  return mKey == dynamic_cast<const IntNode*>(&cRight)->mKey;
}

//********************************************************
// Function: changeKey
//
// Description: Function to change the key of the HNode 
//              to the passed in argument
//              The argument is a void* since the key 
//              of the Node is dependent upon
//              the implementation 
//
// Parameters:  void*
//
// Returned:    none
//		
//********************************************************
void IntNode::changeKey(void*)
{

}

//********************************************************
// Function: outputNode
//
// Description: outputs the key value to the ostream
//
// Parameters:  os      - the ostream where the output will be sent
//
// Returned:    none
//		
//********************************************************
void IntNode::outputNode(std::ostream& os) const
{
  os << mKey;
}

//********************************************************
// Function: getKey
//
// Description: Function to get the current key.  
//              The user must provide an allocated
//              buffer as the first argument and 
//              the size of the buffer as the second
//              argument.  Any errors return false. 
//
// Parameters:  void* - allocated buffer
//              int   - size of the buffer
//
// Returned:    false if error
//		
//********************************************************
bool IntNode::getKey(void *, int) const
{
  return false;
}

//********************************************************
// Function: getKey
//
// Description: this method allows the key to be changed based upon some
//              other data.  
//              this might calculate a new key and then call changeKey.
//              return true on success or false on error 
//              errors include incorrect or incorrectly sized data
//              being sent to the function
//
// Parameters:  void* - allocated buffer
//              int   - size of the buffer
//
// Returned:    false if error
//		
//********************************************************
bool IntNode::updateKey(void *, int) 
{
  return false;
}