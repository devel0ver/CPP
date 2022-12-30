#ifndef FINALTREE_H
#define FINALTREE_H

// Create a template that will work for different data types
template <class T>
class FinalTree{
private:
    struct TreeNode
    {
        T value;            // The value in the node
        TreeNode *left;     // Pointer to left child node
        TreeNode *right;    // Pointer to right child node
    };
    
    TreeNode *root;         // Pointer to the root node

    // Private member functions
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(T, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;

public:
    // Constructor
    FinalTree() { root = nullptr; }

    // Destructor
    ~FinalTree() { destroySubTree(root); }

    // Binary Tree Operations
    void insertNode(T);
    void remove(T);
    bool searchNode(T);

    void displayInOrder() const 
        { displayInOrder(root); }
    void displayPreOrder() const
        { displayPreOrder(root); }
    void displayPostOrder() const
        { displayPostOrder(root); }
};
#endif