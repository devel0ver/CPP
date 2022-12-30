#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Link
{
private:
    int myData; // Data of each link
    Link *nextThing; // next link of link

public:
    // constructor
    Link(){
        myData=-1;
        nextThing = NULL;
    }

    // Settler function
    void setMyData(int);
    void setNextThing(Link *);

    // getter function
    int getMyData();
    Link* getNextThing();
};

// Linked list of all linked
class MyLinkedList
{
private:
    Link *root;
public:
    // constructor
    MyLinkedList(){root = NULL;}

    void insert(int);
    void print();   // Displaying all values in list
};

#endif