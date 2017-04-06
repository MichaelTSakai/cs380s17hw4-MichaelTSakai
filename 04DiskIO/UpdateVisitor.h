#pragma once

#include "IVisitor.h"

class UpdateVisitor : public IVisitor
{
public:
  UpdateVisitor(void*, int);
  void visit(IntNode &rcIntNode);
  void visit(DiskIONode &rcDiskIONode);
private:
  void *pmBuffer;
  int mSize;
};