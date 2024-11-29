#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() : head(nullptr), current(nullptr), size(0) {}

CircularLinkedList::~CircularLinkedList() {
    if (!isEmpty()) {
        Node* temp = head;
        Node* nextNode;
        do {
            nextNode = temp->getNext();
            delete temp;
            temp = nextNode;
        } while (temp != head);
    }
}

void CircularLinkedList::addPlayer(Player* player) {
    Node* newNode = new Node(player);
    if (isEmpty()) {
        head = newNode;
        current = head;
        head->setNext(head);
    }
    else {
        Node* temp = head;
        while (temp->getNext() != head) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
        newNode->setNext(head);
    }
    size++;
}

Node* CircularLinkedList::getCurrent() const {
    return current;
}

void CircularLinkedList::moveToNext() {
    if (current) {
        current = current->getNext();
    }
}

bool CircularLinkedList::isEmpty() const {
    return size == 0;
}
