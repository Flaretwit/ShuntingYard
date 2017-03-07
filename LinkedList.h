//LinkedList.h
template <typename T>
struct LLNode {
  LLNode<T>* next;
  T* data;
};

template <typename T>
class LinkedList {
public:
  //adds at a specific index
  void addAt(int index, LLNode<T>*, LLNode<T>*);
  LinkedList();
  //note this adds to the end.
  void add(LLNode<T>*);
  LLNode<T>* getHead();
  LLNode<T>* deleteNode(int index);
private:
  LLNode<T>* head;
};

//Has to be the same file because templates
template <typename T>
LinkedList<T>::LinkedList() {
  LLNode<T>* head = NULL;
}


//adds at a specific index recursively
template <typename T>
void LinkedList<T>::addAt(int index, LLNode<T>* node, LLNode<T>* head) {
  //the case where index to be added
  if(index == 0) {
      node->next = head;
      head = node;
  }
  else {
    index--;
    head = head->next;
    addAt(index, node, getHead());
  }
}

//returns the head of the LinkedList
template <typename T>
LLNode<T>* LinkedList<T>::getHead() {
  return head;
}

//deletes a node given the index of the Node.
//NEEDS ERROR CHECKING
template <typename T>
LLNode<T>* LinkedList<T>::deleteNode(int index) {
  LLNode<T>* current = head;
  if(index == 0) {
    head = head->next;
    return current;
  }
  while(index != 1) {
    current = current->next;
    index--;
  }
  LLNode<T>* toReturn = current->next;
  current->next = current->next->next;
  return toReturn;
}
