#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include "LeftistNode.h"
#include "Queue.h"

class LeftistHeap
{
public:
    LeftistHeap();
    ~LeftistHeap();
    void insert( long aKey );
    void deleteMin();
    void preorderPrint();
    void inorderPrint();
    void levelorderPrint();
private:
    void preorderPrint( LeftistNode* aNodePtr );
    void inorderPrint(LeftistNode* aNodePtr);
    LeftistNode* merge( LeftistNode* H1, LeftistNode* H2 );
    void postOrderDelete(LeftistNode* aNodePtr);
    void swap( LeftistNode*& H1, LeftistNode*& H2 );
    void swapChildren( LeftistNode*& H1 );

    LeftistNode* mRoot;
};
#endif // !LEFTIST_HEAP_H
