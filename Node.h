#ifndef NODE_H
#define NODE_H

#include "Player.h"

class Node {
public:
    Node(Player* player);

    Player* getPlayer() const;
    Node* getNext() const;
    void setNext(Node* next);

private:
    Player* player;
    Node* next;
};

#endif // Node.h

