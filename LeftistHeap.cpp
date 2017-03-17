#include "LeftistHeap.h"
#include <iostream>

LeftistHeap::LeftistHeap()
{
    mRoot = nullptr;
}

LeftistHeap::~LeftistHeap()
{
    if( mRoot )
    {
        postOrderDelete( mRoot );
    }
}

void LeftistHeap::insert( long aKey )
{
    if( !mRoot )
    {
        mRoot = new LeftistNode( aKey );
    }
    else
    {
        LeftistNode* newNode = new LeftistNode( aKey );
        mRoot = merge( newNode, mRoot );
    }
}

void LeftistHeap::deleteMin()
{
    if( mRoot )
    {
        LeftistNode* deletionTarget = mRoot;

        mRoot = merge( mRoot->getLeftChild(), mRoot->getRightChild() );

        delete deletionTarget;
    }
}

void LeftistHeap::preorderPrint()
{
    if( mRoot )
    {
        preorderPrint( mRoot );
    }
}

void LeftistHeap::inorderPrint()
{
    if( mRoot )
    {
        inorderPrint( mRoot );
    }
}

void LeftistHeap::levelorderPrint()
{
    if( mRoot )
    {
        Queue<LeftistNode*> nodeQueue;
        LeftistNode* currentNode;
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

void LeftistHeap::preorderPrint( LeftistNode * aNodePtr )
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

void LeftistHeap::inorderPrint( LeftistNode *aNodePtr )
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

LeftistNode* LeftistHeap::merge( LeftistNode* H1, LeftistNode* H2 )
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

    H1->setRightChild( merge( H1->getRightChild(), H2 ) );
    H1->adjustRank();

    LeftistNode* leftChildExists = H1->getLeftChild();
    LeftistNode* rightChildExists = H1->getRightChild();

    if( !leftChildExists && rightChildExists )
    {
        swapChildren( H1 );
    }
    else if( ( leftChildExists && rightChildExists ) && ( H1->getLeftChild()->getRank() < H1->getRightChild()->getRank() ) )
    {
        swapChildren( H1 );
    }

    return H1;
}

void LeftistHeap::postOrderDelete( LeftistNode * aNodePtr )
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

void LeftistHeap::swap( LeftistNode *& H1, LeftistNode *& H2 )
{
    LeftistNode* tempNode = H1;
    H1 = H2;
    H2 = tempNode;
}

void LeftistHeap::swapChildren( LeftistNode*& H1 )
{
    LeftistNode* temp = H1->getLeftChild();

    H1->setLeftChild( H1->getRightChild() );
    H1->setRightChild( temp );
}

