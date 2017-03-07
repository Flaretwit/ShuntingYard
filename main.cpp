//Shunting Yard Algorithm. Uses LinkedLists to implement a stack, which then acts
//as a infix translator between prefix, infix and postfix.
//main.cpp
#include <iostream>
#include <vector>
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

LLNode<char>* pop(LinkedList<char>*&);
void push(LinkedList<char> *&, LLNode<char>*);
LLNode<char>* peek(LinkedList<char> *);
LLNode<char>* makeNode(char );
using namespace std;

int main() {
  LinkedList<char>* ll = new LinkedList<char>;
  char* input = new char[80];
  vector<char> output;
  cout << "Shunting Yard Algorithm" << endl;
  cout << "Enter the mathematical expression." << endl;
  cin.getline(input, 80);

  bool done = false;


  while(!done) {
    char* token = new char[80];
    int i;
    for(int i = 0; *input != ' ' && *input != '\0'; i++, input++) {
      token[i] = *input;
    }
    if(*input == '\0') {
      while(peek(ll)->data != 0) {
        output.push_back(*(pop(ll)->data));
      }
    }
    if(isdigit(token[0])) {
      output.push_back(token[0]);
    }
    else {
      //if first token is a left parentheses.
      if(token[0] == '(') {
          push(ll, makeNode(token[0]));
      }
      //if first token is a right parentheses
      else if(token[0] == ')') {
        while(*(peek(ll)->data) != '(') {
            output.push_back(*(pop(ll)->data));
        }
        //removes the left parentheses.
        pop(ll);
      }
      //if stack is empty or contains a '(', push operator.
      else if((token[0] == '+' || token[0] == '-' ||
            token[0] == '*' || token[0] == '/' || token[0] == '^')
            && (ll->getHead() == NULL || *(peek(ll)->data) == '(')) {
         push(ll, makeNode(token[0]));
      }
       //pops from stack until operator is of higher precedence, then pushes
       //the new operator onto the stack.
       else {
         bool finished = false;
         while(!finished) {
           if(token[0] == '^' && *(peek(ll)->data) != '^') {
               finished = true;
               push(ll, makeNode(token[0]));
           }
           else if((token[0] == '*' || token[0] == '/')
           && (*(peek(ll)->data) == '+' || *(peek(ll)->data) == '-')) {
             finished = true;
             push(ll, makeNode(token[0]));
           }
           else {
             output.push_back(*pop(ll)->data);
           }
         }
       }
    }

  }
  return 0;
}
//does the operation when the character is a digit

//gets the information for a node
LLNode<char>* makeNode(char token) {
  LLNode<char>* node = new LLNode<char>();
  node->data = &token;
  return node;
}
LLNode<char>* peek(LinkedList<char>* ll) {
  return ll->getHead();
}

//returns the most recent node in the stack.
LLNode<char>* pop(LinkedList<char>*& ll) {
  return ll->deleteNode(0);
}
//adds a node to the top of the stack (implemented as a Linkedlist)
void push(LinkedList<char>*& ll, LLNode<char>* node) {
  ll->addAt(0, node, ll->getHead());
}
