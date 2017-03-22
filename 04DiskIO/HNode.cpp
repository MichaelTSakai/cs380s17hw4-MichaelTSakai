//***************************************************************************
// File name:	HNode.h
// Author:		Michael Sakai
// Date:			03/21/2017
// Class:			CS380
// Assignment:Disk Scheduling
// Purpose:		Implements HNode.h
//**************************************************************************
#include "HNode.h"

//********************************************************
// Function: operator<<
//
// Description: calls the outputNode function to give output to the
//              ostream
//
// Parameters:  os      - the ostream where the output will be sent
//              theHeap - Heap object that provides outputNode
//
// Returned:    os - updated ostream
//		
//********************************************************
std::ostream& operator<<(std::ostream &os, const HNode &theNode)
{
  theNode.outputNode(os);
  return os;
}