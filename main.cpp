//Shunting Yard Algorithm. Uses LinkedLists to implement a stack, which then acts
//as a infix translator between prefix, infix and postfix.
//main.cpp
#include <iostream>
#include <vector>
#include "Node.h"

Node* pop(Node*& head);
void push(Node*& head, Node* newNode);
int precedence(char c);
bool isOperator(char c);
using namespace std;

int main() {
  char* input = new char[80];
  cout << "Shunting Yard Algorithm" << endl;
  cout << "Enter the mathematical expression." << endl;
  cin.get(input, 80);
  cin.ignore();
  
  Node* head = NULL;
  bool done = false;
  //cout << "hellO" << endl;

  while(!done) {
    char* token = new char[80];
    int i = 0;
    for(int i = 0; *input != ' ' && *input != '\0'; i++, input++) {
      token[i] = *input;
    }
    input++;
    //cout << "Token: (" << token[0] << ")" << endl;
    //when the expression has been completely read
    //pops all the remaning operators in the stack into the output
    if(token[0] == '\0') {
      while(head != NULL) {
            cout << pop(head)->getData() << flush;
      }
      done = true;
    }
    //if token is an digit, immediately prints it
    else if(isdigit(token[0])) {
      //cout << "Is a digit." << endl;
      cout << token[0] << flush;
    }
    //if token is a left parentheses, push onto stack
    else if(token[0] == '(') {
        Node* node = new Node(token[0]);
        push(head, node);
    }
    //if token is a right parentheses, discrd it, then print and pop stack
    //until a left parentheses is found.
    else if(token[0] == ')') {
        while(head->getData() != '(') {
          cout << pop(head)->getData() << flush;
        }
        //gets rid of left parentheses.
        pop(head);
    }
    //if the stack is empty or contains a left parentheses on top, push operator
    else if(head == NULL || head->getData() == '(') {
      //cout << "First time?" << flush;
      Node* node = new Node(token[0]);
      push(head, node);
    }
    //if token is an operator, pop the stack until the operator on top
    //has the same or higher precedence. Then pushes the operator
    else if(isOperator(token[0])) {
      while(precedence(token[0]) < precedence(head->getData())) {
        cout << pop(head)->getData() << flush;
        //if head is now null, breka out of the loop
        if(head == NULL) {
          break;
        }
      }
      //cout << "direcly here already" << flush;
      Node* node = new Node(token[0]);
      push(head, node);
    }

}
  return 0;


}
int precedence(char c) {
  if(c == '+' || c == '-') {
    return 1;
  }
  if(c == '*' || c == '/') {
    return 2;
  }
  if(c == '^') {
    return 3;
  }
}

bool isOperator(char c) {
  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    return true;
  }
  return false;
}

//returns the most recent node in the stack.
Node* pop(Node*& head) {
  Node* current = head;
  head = head->getNext();
  return current;
}
//adds a node to the top of the stack (implemented as a Linkedlist)
void push(Node*& head, Node* node) {
  node->setNext(head);
  head = node;
}
