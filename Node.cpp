#include <iostream>
#include "Node.h"

using namespace std;
//constructs a new Node with data newData
Node::Node(char newData) {
  data = newData;
  next = NULL;
}
//deletes the Node by pointing its next pointer to NULL
Node::~Node() {
  next = NULL;
}
//returns the data (character) in the Node
char Node::getData() {
  return data;
}
//sets the next pointer to a Node.
void Node::setNext(Node* newNode) {
  next = newNode;
}

Node* Node::getNext() {
  return next;
}
