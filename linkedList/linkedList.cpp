#include <iostream>
#include "linkedList.h"
using namespace std;

int *head = nullptr;

void Link::setMyData(int data)
{
    myData = data;
}

void Link::setNextThing(Link *n)
{
    nextThing = n;
}

int Link::getMyData()
{
    return(myData);
}
Link* Link::getNextThing()
{
    return(nextThing);
}

void MyLinkedList::insert(int data)
{
    Link *node = new Link();    // create new node
    // set data of each link
    node->setMyData(data);
    node->setNextThing(root);
    root = node;
}

void MyLinkedList::print()
{
    Link *lst = root;
    while (lst!=NULL)
    {
        cout << lst->getMyData() << " ";
        lst = lst->getNextThing();     // go to next link
    } 
}