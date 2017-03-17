#include "LeftistNode.h"

LeftistNode::LeftistNode( long aKey )
{
    mKey = aKey;
    mRank = 1;
    mLeftChild = nullptr;
    mRightChild = nullptr;
}

long LeftistNode::getRank()
{
    return mRank;
}

long LeftistNode::getKey()
{
    return mKey;
}

void LeftistNode::setLeftChild( LeftistNode * aLeftChild )
{
    mLeftChild = aLeftChild;
}

void LeftistNode::setRightChild( LeftistNode * aRightChild )
{
    mRightChild = aRightChild;
}
LeftistNode* LeftistNode::getLeftChild()
{
    return mLeftChild;
}

LeftistNode* LeftistNode::getRightChild()
{
    return mRightChild;
}

void LeftistNode::adjustRank()
{
    if( !mLeftChild )
    {
        mRank = 1;
    }
    else if( !mRightChild )
    {
        mRank = 1;
    }
    else
    {
        mRank = minVal( mLeftChild->getRank(), mRightChild->getRank() ) + 1;
    }
}

long LeftistNode::minVal( long aVal1, long aVal2 )
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
