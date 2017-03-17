#ifndef LEFTIST_NODE_H
#define LEFTIST_NODE_H

class LeftistNode
{
public:
    LeftistNode(long aKey);
    long getRank();
    long getKey();
    void setLeftChild( LeftistNode* aLeftChild );
    void setRightChild( LeftistNode* aRightChild );
    LeftistNode* getLeftChild();
    LeftistNode* getRightChild();
    void adjustRank();
private:
    long minVal( long aVal1, long aVal2 );
    long mRank;
    long mKey;
    LeftistNode* mLeftChild;
    LeftistNode* mRightChild;
};
#endif