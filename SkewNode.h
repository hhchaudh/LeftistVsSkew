#ifndef SKEW_NODE_H
#define SKEW_NODE_H

class SkewNode
{
public:
    SkewNode(long aKey);
    long getKey();
    void setLeftChild( SkewNode* aLeftChild );
    void setRightChild( SkewNode* aRightChild );
    SkewNode* getLeftChild();
    SkewNode* getRightChild();
private:
    long minVal( long aVal1, long aVal2 );
    long mKey;
    SkewNode* mLeftChild;
    SkewNode* mRightChild;
};
#endif