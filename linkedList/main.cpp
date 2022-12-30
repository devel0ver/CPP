#include <iostream>
#include "linkedList.cpp"
using namespace std;

int main()
{
    MyLinkedList linkedList;
    int data;
    for (int i = 0; i < 8; i++)
    {
        cout << "Enter value " << i+1 << ": ";
        cin >> data;
        linkedList.insert(data);
    }

    //  Display everything in the list
    cout << "List contains: ";
    linkedList.print();

    cout << "\n";
    return 0;
}