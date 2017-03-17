#ifndef SKEW_HEAP_H
#define SKEW_HEAP_H

#include "SkewNode.h"
#include "Queue.h"

class SkewHeap
{
public:
    SkewHeap();
    ~SkewHeap();
    void insert( long aKey );
    void deleteMin();
    void preorderPrint();
    void inorderPrint();
    void levelorderPrint();
private:
    void preorderPrint( SkewNode* aNodePtr );
    void inorderPrint(SkewNode* aNodePtr);
    SkewNode* merge( SkewNode* H1, SkewNode* H2 );
    void postOrderDelete(SkewNode* aNodePtr);
    void swap( SkewNode*& H1, SkewNode*& H2 );
    void swapChildren( SkewNode*& H1 );

    SkewNode* mRoot;
};
#endif // !LEFTIST_HEAP_H
