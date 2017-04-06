#include "UpdateVisitor.h"

UpdateVisitor::UpdateVisitor(void *pBuffer, int size)
{
  pmBuffer = pBuffer;
  mSize = size;
}

void UpdateVisitor::visit(IntNode &rcIntNode)
{
  rcIntNode.updateKey(pmBuffer, mSize);
}
void UpdateVisitor::visit(DiskIONode &rcDiskIONode)
{
  rcDiskIONode.updateKey(pmBuffer, mSize);
}