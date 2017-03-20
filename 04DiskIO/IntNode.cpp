#include "IntNode.h"


IntNode::~IntNode() 
{
}

bool IntNode::operator<(ComparableItem const &right) const
{
  return mValue < dynamic_cast<const IntNode*>(&right)->mValue;
}

bool IntNode::operator>(ComparableItem const &right) const
{
  return mValue > dynamic_cast<const IntNode*>(&right)->mValue;
}
bool IntNode::operator== (ComparableItem const  &right) const
{
  return mValue == dynamic_cast<const IntNode*>(&right)->mValue;
}

void IntNode::changeKey(void*)
{

}

void IntNode::outputNode(std::ostream& os) const
{
  os << mValue;
}

bool IntNode::getKey(void *, int) const
{
  return false;
}

bool IntNode::updateKey(void *, int) 
{
  return false;
}