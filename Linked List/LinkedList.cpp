#include <iostream>

using namespace std;

class Node{
  public:
    Node* Next;
    int data;
    Node(int value){
      Next = NULL;
      data = value;
    };
};

class LinkedList{
  public:
    Node* Root;
    int size;
    LinkedList(){Root = NULL;};
    LinkedList(int data){
      Root = new Node(data);
      size = 1;
    };
    Node* add(int value, Node* current){
      if(current->Next != NULL){
        current->Next = add(value, current->Next);
      }else{
        size++;
        current->Next = new Node(value);
      }
    }
    void f_traverse(Node* current){
      cout << current->data << "->";
      if(current->Next != NULL){
        f_traverse(current->Next);
      }
    }
    void r_traverse(Node* current){
      if(current->Next != NULL){
        r_traverse(current->Next);
      }
      cout << current->data << "->";
    };
    int getSize(){
      return size;
    }
    void removeFirst(){
      if(Root->Next != NULL){
        Node* oldRoot = Root;
        Root = Root->Next;
        delete oldRoot;
      }
    }

    void removeLast(Node* current){
      if(current->Next != NULL){
        removeLast(current->Next);
      }
      delete current;
    }
};

int main(){
  LinkedList* L = new LinkedList(10);
  L->add(6, L->Root);
  L->add(8, L->Root);

  cout << "Forward traversal: ";
  L->f_traverse(L->Root);
  cout << endl;

  cout << "Reverse traversal: ";
  L->r_traverse(L->Root);
  cout << endl;

  cout << "\nThe list has a size of " << L->getSize() << endl;

  L->removeFirst();
  L->f_traverse(L->Root);
  cout << endl;

  L->removeLast(L->Root);
  L->f_traverse(L->Root);
  cout << endl;
}
