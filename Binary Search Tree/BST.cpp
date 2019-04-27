#include <iostream>

using namespace std;

class Node{
	public:
		int key;
		Node* Left = NULL;
		Node* Right = NULL;
		Node(int value){
			key = value;
		}
};

class BST{
	public:
		Node* Root;
		BST(){
			Root = NULL;
		};
		BST(int i){
			Root = new Node(i);
		};
		Node* insert(int value, Node* current){
			if(current == NULL){
				return new Node(value); 
			}
			if(value <= current->key){
				current->Left = insert(value, current->Left);
			}
			else if(value >= current->key){
				current->Right = insert(value, current->Right);
			}
			return current;
			
		};
		void InorderT(Node* current){
			if(current != NULL){
				InorderT(current->Left);
				cout<< current-> key << " ";
				InorderT(current->Right);
			};
		};
		void Preorder(Node* current){
			if(current != NULL){
				cout<< current-> key << " ";
				Preorder(current->Left);
				Preorder(current->Right);
			};
		};
		void Postorder(Node* current){
			if(current != NULL){
				Postorder(current->Left);
				Postorder(current->Right);
				cout<< current-> key << " ";
			};
		};
};

int main(){
	BST* mytree = new BST(1);
	mytree->insert(2, mytree->Root);
	mytree->insert(3, mytree->Root);
	mytree->insert(4, mytree->Root);
	mytree->insert(5, mytree->Root);
	mytree->InorderT(mytree->Root);
	cout << " \n" <<endl;
	mytree->Preorder(mytree->Root);
	cout << " \n" <<endl;
	mytree->Postorder(mytree->Root);
	cout << " \n" <<endl;
}