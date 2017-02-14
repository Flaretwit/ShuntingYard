//Shunting Yard Algorithm. Uses LinkedLists to implement a stack, which then acts
//as a infix translator between prefix, infix and postfix.
//main.cpp
#include "LinkedList.h"
#include <iostream>
#include <vector>

LLNode<T>* pop(LinkedList*& ll);
void push(LLNode<T>*);

using namespace std;

int main() {
  LinkedList*s ll = new LinkedList();
  char* input = new char[80];
  cout << "Shunting Yard Algorithm" << endl;

  return 0;
}
//returns the most recent node in the stack.
LLNode<T>* pop(LinkedList*& ll) {
  return ll->deleteNode(0);
}

void push(LinkedList*& ll, LLNode<T>* node) {
  ll->addAt(0, node);
}
