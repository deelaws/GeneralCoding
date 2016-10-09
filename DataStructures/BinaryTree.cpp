#include "stdafx.h"

using namespace DataStructs;

BinaryTree::BinaryTree(int rootValue)
{
    this->root.reset((BinaryTreeNode*)malloc(sizeof(BinaryTreeNode)));
    this->root->value = rootValue;
}



void BinaryTree::Insert(int value)
{
    // Use breatdh first search to find the first node that is null.
    // this will insure that the tree remains balanaced. (not a gurantee though
}