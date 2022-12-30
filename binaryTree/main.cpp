#include <iostream>
#include "binaryTree.cpp"
using namespace std;

const int NUM_NODES = 5;

int main()
{
    FinalTree<int> June13Tree;

    cout << "\nInserting nodes.\n";
    June13Tree.insertNode(17);
    June13Tree.insertNode(11);
    June13Tree.insertNode(25);
    June13Tree.insertNode(30);
    cout << "Done.\n\n";

    // Displaying the values inorder
    cout << "The values in the tree inorder: ";
    June13Tree.displayInOrder();
    cout << "\n\n";

    // Displaying the values preorder
    cout << "The values in the tree preorder: ";
    June13Tree.displayPreOrder();
    cout << "\n\n";

    // Displaying the values postorder
    cout << "The values in the tree postorder: ";
    June13Tree.displayPostOrder();
    cout << "\n\n";

    cout << "Removing the value 30 in the tree...\n";
    June13Tree.remove(30);
    cout << "Done.\n\n";

    // Displaying the values inorder after removing a value
    cout << "The values in the tree inorder: ";
    June13Tree.displayInOrder();
    cout << "\n\n";

    // Displaying the values preorder after removing a value
    cout << "The values in the tree preorder: ";
    June13Tree.displayPreOrder();
    cout << "\n\n";

    // Displaying the values postorder after removing a value
    cout << "The values in the tree postorder: ";
    June13Tree.displayPostOrder();
    cout << "\n\n";
    return 0;
}
