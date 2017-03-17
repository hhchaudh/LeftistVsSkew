/**
*	@file : LeftistNode.h
*	@author :  Haaris Chaudhry
*	@date : Mar 16, 2017
*	Purpose: This class will perform the functions of a leftist node
*/
#ifndef LEFTIST_NODE_H
#define LEFTIST_NODE_H

class LeftistNode
{
public:
    /**
    * The leftist node constructor
    * @param aKey The value that the node will store in mKey
    * @return A node with aKey as its internal mKey
    */
    LeftistNode(long aKey);

    /**
    * This function retrieves the rank of the node
    * @return The rank of the node
    */
    long getRank();

    /**
    * This function return the value stored in mKey
    * @return The value stored in mKey
    */
    long getKey();

    /**
    * Sets the left child of the node
    * @param aLeftChild A pointer pointing to a node that will be assigned to mLeftChild
    */
    void setLeftChild( LeftistNode* aLeftChild );

    /**
    * Sets the right child of the node
    * @param aRightChild A pointer pointing to a node that will be assigned to mRightChild
    */
    void setRightChild( LeftistNode* aRightChild );

    /**
    * Retrieves a copy of mLeftChild
    * @return A copy of mLeftChild
    */
    LeftistNode* getLeftChild();

    /**
    * Retrieves a copy of mRightChild
    * @return A copy of mRightChild
    */
    LeftistNode* getRightChild();

    /**
    * Adjusts the rank of the current node
    */
    void adjustRank();
private:
    /**
    * Calculates the minimum of two values
    * @param aVal1 The first value to be compared
    * @param aVal2 The second value to be compared
    * @return The value that is the smallest
    */
    long minVal( long aVal1, long aVal2 );

    long mRank;                 //!< The rank of the node
    long mKey;                  //!< The value contained within the node
    LeftistNode* mLeftChild;    //!< A pointer to the left child of the node
    LeftistNode* mRightChild;   //!< A pointer to the right child of the node
};
#endif