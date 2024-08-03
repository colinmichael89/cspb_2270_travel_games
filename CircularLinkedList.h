#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "Node.h"

class CircularLinkedList {
public:
    CircularLinkedList();
    ~CircularLinkedList();

    void addPlayer(Player* player);
    Node* getCurrent() const;
    void moveToNext();
    bool isEmpty() const;

private:
    Node* head;
    Node* current;
    int size;
};

#endif // CircularLinkedList.h
