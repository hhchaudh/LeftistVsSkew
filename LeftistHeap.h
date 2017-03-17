/**
*	@file : LeftistHeap.h
*	@author :  Haaris Chaudhry
*	@date : Mar 16, 2017
*	Purpose: This class will perform the functions of a leftist heap
*/

#ifndef LEFTIST_HEAP_H
#define LEFTIST_HEAP_H

#include "LeftistNode.h"
#include "Queue.h"

class LeftistHeap
{
public:
    /**
    * Constructor for the Leftist Heap
    * @return A Leftist Heap with a null root
    */
    LeftistHeap();

    /**
    * Destructor for the Leftist Heap
    */
    ~LeftistHeap();

    /**
    * The insertion function will take a value and insert it into the heap using the merge()
    * @param aKey The value to be inserted
    */
    void insert( long aKey );

    /**
    * The deleteMin function will delete the minimum value and will then use merge() to merge the two remaining subtrees
    * @param aKey The value to be inserted
    */
    void deleteMin();

    /**
    * This function prints the values in the heap using a preorder traversal
    */
    void preorderPrint();

    /**
    * This function prints the values in the heap using an inorder traversal
    */
    void inorderPrint();

    /**
    * This function prints the values in the heap using a levelorder traversal
    */
    void levelorderPrint();
private:
    /**
    * This function prints the values in the heap using a preorder traversal
    * @param aNodePtr The root of the current subtree
    */
    void preorderPrint( LeftistNode* aNodePtr );

    /**
    * This function prints the values in the heap using a inorder traversal
    * @param aNodePtr The root of the current subtree
    */
    void inorderPrint(LeftistNode* aNodePtr);

    /**
    * This function will merge two tree together
    * @param H1 The root of the first subtree
    * @param H2 The root of the second subtree
    */
    LeftistNode* merge( LeftistNode* H1, LeftistNode* H2 );

    /**
    * This function is used by the destructor to delete all nodes in the tree
    * @param aNodePtr The root of the current subtree
    */
    void postOrderDelete(LeftistNode* aNodePtr);

    /**
    * This function will swap two trees
    * @param H1 The root of the first subtree
    * @param H2 The root of the second subtree
    */
    void swap( LeftistNode*& H1, LeftistNode*& H2 );

    /**
    * This function will swap the children of a node
    * @param H1 The node with children that need to be swapped
    */
    void swapChildren( LeftistNode*& H1 );

    LeftistNode* mRoot;         //!< The root of the heap
};
#endif // !LEFTIST_HEAP_H
