#include "Node.h"

Node::Node(Player* player) : player(player), next(nullptr) {}

Player* Node::getPlayer() const {
    return player;
}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node* next) {
    this->next = next;
}
