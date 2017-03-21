#include "IntNode.h"

IntNode::IntNode()
{

}

IntNode::IntNode(int key)
{
  mKey = key;
}

IntNode::~IntNode() 
{
}

bool IntNode::operator<(ComparableItem const &right) const
{
  return mKey < dynamic_cast<const IntNode*>(&right)->mKey;
}

bool IntNode::operator>(ComparableItem const &right) const
{
  return mKey > dynamic_cast<const IntNode*>(&right)->mKey;
}
bool IntNode::operator== (ComparableItem const  &right) const
{
  return mKey == dynamic_cast<const IntNode*>(&right)->mKey;
}

void IntNode::changeKey(void*)
{

}

void IntNode::outputNode(std::ostream& os) const
{
  os << mKey;
}

bool IntNode::getKey(void *, int) const
{
  return false;
}

bool IntNode::updateKey(void *, int) 
{
  return false;
}