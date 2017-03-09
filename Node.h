#include  <iostream>
//Node.h
using namespace std;

/*Node class
Used in the implementation of a singly-linked LinkedList

Members:
private char data - holds the character or token for the Algorithm
Node* next - a pointer to the next Node in the LinkedList
Methods:
*/

class Node {
public:
  //adds at a specific index
  Node(char data);
  ~Node();
  char getData();
  void setNext(Node* newNode);
  Node* getNext();
private:
  char data;
  Node* next;
};
