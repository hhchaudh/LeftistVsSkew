#include "SkewNode.h"

SkewNode::SkewNode( long aKey )
{
    mKey = aKey;
    mLeftChild = nullptr;
    mRightChild = nullptr;
}

long SkewNode::getKey()
{
    return mKey;
}

void SkewNode::setLeftChild( SkewNode * aLeftChild )
{
    mLeftChild = aLeftChild;
}

void SkewNode::setRightChild( SkewNode * aRightChild )
{
    mRightChild = aRightChild;
}
SkewNode* SkewNode::getLeftChild()
{
    return mLeftChild;
}

SkewNode* SkewNode::getRightChild()
{
    return mRightChild;
}

long SkewNode::minVal( long aVal1, long aVal2 )
{
    if( aVal1 <= aVal2 )
    {
        return aVal1;
    }
    else
    {
        return aVal2;
    }
}
