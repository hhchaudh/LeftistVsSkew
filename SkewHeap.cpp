#include "SkewHeap.h"
#include <iostream>

SkewHeap::SkewHeap()
{
    mRoot = nullptr;
}

SkewHeap::~SkewHeap()
{
    if( mRoot )
    {
        postOrderDelete( mRoot );
    }
}

void SkewHeap::insert( long aKey )
{
    if( !mRoot )
    {
        mRoot = new SkewNode( aKey );
    }
    else
    {
        SkewNode* newNode = new SkewNode( aKey );
        mRoot = merge( newNode, mRoot );
    }
}

void SkewHeap::deleteMin()
{
    if( mRoot )
    {
        SkewNode* deletionTarget = mRoot;

        mRoot = merge( mRoot->getLeftChild(), mRoot->getRightChild() );

        delete deletionTarget;
    }
}

void SkewHeap::preorderPrint()
{
    if( mRoot )
    {
        preorderPrint( mRoot );
    }
}

void SkewHeap::inorderPrint()
{
    if( mRoot )
    {
        inorderPrint( mRoot );
    }
}

void SkewHeap::levelorderPrint()
{
    if( mRoot )
    {
        Queue<SkewNode*> nodeQueue;
        SkewNode* currentNode;
        nodeQueue.enqueue( mRoot );
        nodeQueue.enqueue( nullptr );

        while( !nodeQueue.isEmpty() )
        {
            currentNode = nodeQueue.peekFront();

            if( currentNode )
            {
                std::cout << currentNode->getKey() << " ";

                if( currentNode->getLeftChild() )
                {
                    nodeQueue.enqueue( currentNode->getLeftChild() );
                }

                if( currentNode->getRightChild() )
                {
                    nodeQueue.enqueue( currentNode->getRightChild() );
                }

                nodeQueue.dequeue();
            }
            else
            {
                nodeQueue.dequeue();
                std::cout << std::endl;
                if( !nodeQueue.isEmpty() )
                {
                    nodeQueue.enqueue( nullptr );
                }
            }
        }
    }
}

void SkewHeap::preorderPrint( SkewNode * aNodePtr )
{
    std::cout << aNodePtr->getKey() << " ";

    if( aNodePtr->getLeftChild() )
    {
        preorderPrint( aNodePtr->getLeftChild() );
    }

    if( aNodePtr->getRightChild() )
    {
        preorderPrint( aNodePtr->getRightChild() );
    }
}

void SkewHeap::inorderPrint( SkewNode *aNodePtr )
{
    if( aNodePtr->getLeftChild() )
    {
        inorderPrint( aNodePtr->getLeftChild() );
    }

    std::cout << aNodePtr->getKey() << " ";

    if( aNodePtr->getRightChild() )
    {
        inorderPrint( aNodePtr->getRightChild() );
    }
}

SkewNode* SkewHeap::merge( SkewNode* H1, SkewNode* H2 )
{
    if( !H1 )
    {
        return H2;
    }
    else if( !H2 )
    {
        return H1;
    }
    else if( H1->getKey() > H2->getKey() )
    {
        swap( H1, H2 );
    }

    SkewNode* temp = H1->getRightChild();
    H1->setRightChild( H1->getLeftChild() );
    H1->setLeftChild( merge( temp, H2 ) );
    return H1;
}

void SkewHeap::postOrderDelete( SkewNode * aNodePtr )
{
    if( aNodePtr->getLeftChild() )
    {
        postOrderDelete( aNodePtr->getLeftChild() );
    }

    if( aNodePtr->getRightChild() )
    {
        postOrderDelete( aNodePtr->getRightChild() );
    }

    delete aNodePtr;
}

void SkewHeap::swap( SkewNode *& H1, SkewNode *& H2 )
{
    SkewNode* tempNode = H1;
    H1 = H2;
    H2 = tempNode;
}

void SkewHeap::swapChildren( SkewNode*& H1 )
{
    SkewNode* temp = H1->getLeftChild();

    H1->setLeftChild( H1->getRightChild() );
    H1->setRightChild( temp );
}

