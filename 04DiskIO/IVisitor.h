//***************************************************************************
// File name:	IVisitor.h
// Author:		Michael Sakai
// Date:			04/6/2017
// Class:			CS380
// Assignment:Disk Scheduling
// Purpose:		Visitor class that visits and calls the class's update function
//**************************************************************************

#pragma once

#include "IntNode.h"
#include "DiskIONode.h"

class IVisitor
{
public:
  virtual void visit(IntNode &rcIntNode) = 0;
  virtual void visit(DiskIONode &rcDiskIONode) = 0;
};