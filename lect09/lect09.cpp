using namespace std;
#include <iostream>

class BST{

	public:
		BST():root(nullptr){};
		~BST(){
			delete root;
		}
		void preorderPrint(){
			preorderHelper(root);
			cout << endl;
		}
		void inorderPrint(){
			inorderHelper(root);
			cout << endl;
		}
		void postorderPrint(){
			postorderHelper(root);
			cout << endl;
		}
		void insert(int data){
			Node* newNode = new Node;
			newNode->data = data;
			Node* p = root;

			if(!root){
				root = newNode;
				return;
			}

			while(p){
				if(data > p->data){
					if(p->right){
						p = p->right;	
					}
					else{
						p->right = newNode;
						newNode->parent = p;
						break;
					}
				}
				else if(data < p->data){
					if(p->left){
						p = p->left;
					}
					else{
						p->left = newNode;
						newNode->parent = p;
						break;
					}
				}
				else{
					break;
				}
			}
			
		}
		bool search(int data){
			return !!(searchHelper(root, data));
		}
		int predecessor(int data){
			Node* node = searchHelper(root, data);
			if(!node){return 0;}
			node = predecessorHelper(node);
			if(!node){return 0;}
			else{return node->data;}
		}
		int successor(int data){
			Node* node = searchHelper(root, data);
			if(!node){return 0;}
			node = successorHelper(node);
			if(!node){return 0;}
			else{return node->data;}
		}	

	private:
		struct Node{
			Node():left(nullptr), right(nullptr), parent(nullptr){};
			~Node(){
				if(left){
					delete left;
				}
				if(right){
					delete right;
				}
			}
			Node* left;
			Node* right;
			Node* parent;
			int data;
		};
		Node* root;

		void preorderHelper(Node* root){
			if(!root){return;}
			cout << root->data<< " ";
			preorderHelper(root->left);
			preorderHelper(root->right);
		}
		void inorderHelper(Node* root){
			if(!root){return;}
			inorderHelper(root->left);
			cout << root->data << " ";
			inorderHelper(root->right);
		}
		void postorderHelper(Node* root){
			if(!root){return;}
			postorderHelper(root->left);
			postorderHelper(root->right);
			cout << root->data << " ";
		}
		Node* searchHelper(Node* root, int data){
			if(!root){return nullptr;}
			else if(root->data == data){return root;}
			if(data > root->data){
				return searchHelper(root->right, data);
			}
			else{
				return searchHelper(root->left, data);
			}
		}
		Node* predecessorHelper(Node* node){
			if(node->left){
				node = node->left;
				while(node->right){
					node = node->right;
				}
				return node;
			}
			else{
				if(node->parent->right == node){
					return node->parent;
				}
				else{
					while(node->parent && node->parent->parent){
						if(node->parent->parent->right == node->parent){
							return node->parent->parent;
						}
						node = node->parent;
					}
					return nullptr;
				}
			}
		}

		void delete(Node* node){
			if(!(node->right) && !(node->left)){
				if(node->parent->right == node){
					node->parent->right = nullptr;
					delete node;
				}
				else{
					node->parent->left = nullptr;
					delete node;
				}
			}
			
		}

		Node* successorHelper(Node* node){
			if(node->right){
				node = node->right;
				while(node->left){
					node = node->left;
				}
				return node;
			}
			else{
				if(node->parent->left == node){
					return node->parent;
				}
				else{
					while(node->parent && node->parent->parent){
						if(node->parent->parent->left == node->parent){
							return node->parent->parent;
						}
						node = node->parent;
					}
					return nullptr;
				}
			}
		}
};


int main(){
	BST test;
	test.insert(10);
	test.insert(42);
	test.insert(3);
	test.insert(4);
	test.insert(1);
	test.insert(36);
	test.insert(32);
	test.inorderPrint();
	cout << test.predecessor(42) << endl;
	cout << test.predecessor(4) << endl;
	cout << test.predecessor(32) << endl;
	cout << test.successor(10) << endl;
	cout << test.successor(1) << endl;
	cout << test.successor(4) << endl;
	return 0;
}
