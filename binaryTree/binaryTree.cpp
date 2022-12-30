#include <iostream>
#include "binaryTree.h"
using namespace std;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************
template <class T>
void FinalTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode; // Insert the node
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode); // Search the left brach
    else
        insert(nodePtr->right, newNode); // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold item as its value, *
// and passes it to the insert function.                   *
//**********************************************************
template <class T>
void FinalTree<T>::insertNode(T item)
{
    TreeNode *newNode = nullptr; // pointer to a new node

    // Create new node and store item in it.
    newNode = new TreeNode;
    newNode->value = item;
    newNode->right = newNode->left = nullptr;

    // Insert the node
    insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************
template <class T>
void FinalTree<T>::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************
template <class T>
bool FinalTree<T>::searchNode(T item)
{
    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == item)
            return true;
        else if (item < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************
template <class T>
void FinalTree<T>::remove(T item)
{
    deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************
template <class T>
void FinalTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
    if (item < nodePtr->value)
        deleteNode(item, nodePtr->left);
    else if (item > nodePtr->value)
        deleteNode(item, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************
template <class T>
void FinalTree<T>::makeDeletion(TreeNode *&nodePtr)
{
    // define a temporary pointer to use in reattaching
    // the left subtree
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr)
        cout << "Cannot delete empty node!\n";
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; // Reattach left child
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; // Reattach right child
        delete tempNodePtr;
    }
    //  If the node has two children
    else
    {
        // Move one node the right
        tempNodePtr = nodePtr->right;
        // Go to the end left node.
        while (nodePtr->left)
            tempNodePtr = nodePtr->left;
        // Reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Reattach the right subtree
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************
template<class T>
void FinalTree<T>::displayInOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
template<class T>
void FinalTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
template<class T>
void FinalTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";    
    }
}