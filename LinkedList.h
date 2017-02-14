//LinkedList.h
template <type T>
#include <iostream>
#include <vector>

struct LLNode {
  LLNode<T>* next;
  T* data;
}

template <type T>

class LinkedList {
public:
  //adds at a specific index
  void addAt(LLNode<T>*);
  //note this adds to the end.
  void add(LLNode<T>*);
  LLNode<T>* getHead();
  LLNode<T>* deleteNode(int index);
  void setNext(LLNode<T>*);
  LLNode<T>* getNext();
private:
  LLNode<T>* head;
}

//Has to be the same file because templates?
LinkedList::LinkedList() {
  Node* head = new Node();
}
//adds at a specific index recursively
void LinkedList::addAt(int index, LLNode<T>* node) {
  //the case where index to be added
  if(index == 0) {
      node->setNext(head);
      head = node;
  }
  else {
    index--;
    head = head->getNext();
    addAt(index, node, head);
  }
}
//returns the head of the LinkedList
LLNode<T>* LinkedList::getHead() {
  return head;
}
//deletes a node given the index of the Node.
//NEEDS ERROR CHECKING
LLNode<T>* LinkedList::deleteNode(int index) {
  Node* current = head;
  if(index == 0) {
    head = head->next;
    return current;
  }
  while(index != 1) {
    current = current->next;
    index--;
  }
  Node* toReturn = current->next;
  current->next = current->next->next;
  return toReturn;
}
