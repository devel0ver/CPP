#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

template<class ItemType>
class StackInterface
{
public:
    bool isEmpty();
    bool push(ItemType& newEntry);
    bool pop();
    ItemType peek();
    ~StackInterface(){ };
};

#endif