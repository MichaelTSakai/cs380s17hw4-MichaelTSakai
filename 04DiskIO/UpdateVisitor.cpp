//***************************************************************************
// File name:	UpdateVisitor.cpp
// Author:		Michael Sakai
// Date:			04/6/2017
// Class:			CS380
// Assignment:Disk Scheduling
// Purpose:		Implements UpdateVisitor.cpp
//**************************************************************************
#include "UpdateVisitor.h"

//********************************************************
// Constructor: UpdateVisitor
//
// Description: Initialize data members.
//
// Parameters:  pBuffer - buffer used for update function
//							size    - size of buffer
//
// Returned:    none
//		
//********************************************************
UpdateVisitor::UpdateVisitor(void *pBuffer, int size)
{
  pmBuffer = pBuffer;
  mSize = size;
}

//********************************************************
// Function: visit
//
// Description: calls updateKey
//
// Parameters:  rcIntNode - the class that has updateKey
//
// Returned:    none
//		
//********************************************************
void UpdateVisitor::visit(IntNode &rcIntNode)
{
  rcIntNode.updateKey(pmBuffer, mSize);
}

//********************************************************
// Function: visit
//
// Description: calls updateKey
//
// Parameters:  rcDiskIONode - the class that has updateKey
//
// Returned:    none
//		
//********************************************************
void UpdateVisitor::visit(DiskIONode &rcDiskIONode)
{
  rcDiskIONode.updateKey(pmBuffer, mSize);
}