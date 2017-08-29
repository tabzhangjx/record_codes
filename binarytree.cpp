#include <iostream>
#include <stack>
using namespace std;
#define mod template <class T>

mod
class BinaryTreeNode {
private:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
public:
	BinaryTreeNode() :data(NULL), left(NULL), right(NULL) {};
	BinaryTreeNode(const T& elem) :data(elem), left(NULL), right(NULL) {};
	BinaryTreeNode(const T&elem, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r) :data(elem), left(l), right(r) {};
	~BinaryTreeNode() {};
	T value()const { return data; };
	BinaryTreeNode<T>*leftchild()const { return left; };
	BinaryTreeNode<T>*rightchild()const { return right };
	void setleftchild(BinaryTreeNode<T>* left) { this.left = left; };
	void setrightchild(BinaryTreeNode<T>* right) { this.right = right; };
	void setvalue(const T& val) { data = val; };
	void creatnode(BinaryTreeNode<T>* rnode);
	bool isleaf() const { return(left == NULL && right == NULL); };
};

mod
class BinaryTree {
protected:
	BinaryTreeNode<T>* root;
public:
	BinaryTree() { root = NULL; };
	BinaryTree(BinaryTreeNode<T>* r) :root(r) {};
	BinaryTree(T[],int n);
	~BinaryTree() { Deletebt(root); };
	bool isEmpty() { return root == NULL; };
	void visit(BinaryTreeNode<T>* curr) { cout << curr->data << ' '; }
	BinaryTreeNode<T>*& Root() { return root; };
	void CreateTree(const T&data, BinaryTree<T>& ltree, BinaryTree<T>& rtree) { root = new BinaryTreeNode(data, ltree, rtree); };
	void CreateTree(BinaryTreeNode<T>* r);
	void Deletebt(BinaryTreeNode<T>* root);
	void PreOrder(BinaryTreeNode<T>* root);
	void InOrder(BinaryTreeNode<T>* root);
	void PostOrder(BinaryTreeNode<T>* root);
	/*void PreOrderWithoutRecusion(BinaryTreeNode<T>* root);
	void InOrderWithoutRecusion(BinaryTreeNode<T>* root);
	void PostOrderWithoutRecusion(BinaryTreeNode<T>* root);
	void LevelOrder(BinaryTreeNode<T>* root);*/
};

mod
BinaryTree<T>::BinaryTree(T[], int n) {

}

mod
BinaryTree::BinaryTree(T[], int n){

}

mod
inline void BinaryTreeNode<T>::creatnode(BinaryTreeNode<T>* rnode) {
	if (rnode == NULL) {
		return 0;
	}
	this->left = new BinaryTreeNode<T>;
	this->right = new BinaryTreeNode<T>;
	this->left->creatnode(rnode->left);
	this->right->creatnode(rnode->right);
}



mod
inline void BinaryTree<T>:: CreateTree(BinaryTreeNode<T>* r) {
	this->root->creatnode(r);
}



mod
inline void BinaryTree<T>::Deletebt(BinaryTreeNode<T>* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == root->right == NULL) {
		root->~BinaryTreeNode;
	}
	else {
		Deletebt(root->left);
		Deletebt(root->right);
	}
}

mod
inline void BinaryTree<T>::PreOrder(BinaryTreeNode<T>* root) {
	if (root == NULL) {
		return;
	}
	else {}
	visit(root->value());
	PreOrder(root->leftchild());
	PreOrder(root->rightchild());
}

mod
inline void BinaryTree<T>::InOrder(BinaryTreeNode<T>* root) {
	if (root == NULL) {
		return;
	}
	else {}
	InOrder(root->leftchild());
	visit(root->value());
	InOrder(root->rightchild());
}

mod
inline void BinaryTree<T>::PostOrder(BinaryTreeNode<T>* root) {
	if (root == NULL) {
		return;
	}
	else{}
	PostOrder(root->leftchild());
	PostOrder(root->rightchild());
	visit(root->value());
}

/*
mod
inline void BinaryTree<T>::PreOrderWithoutRecusion(BinaryTreeNode<T>* root) {

}

mod
inline void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T>* root) {

}

enum Tag { L, R };
mod
class StackNode {
public:
	BinaryTreeNode<T>* pointer;
	Tag tag;
};
mod
void BinaryTree<T>::PostOrderWithoutRecusion(BinaryTreeNode<T>* root) {
	stack<StackNode<T>> tStack;
	StackNode<T> Node;
	BinaryTreeNode<T>* pointer = root;
	do {
		while (pointer != NULL) {
			Node.pointer = pointer;
			Node.tag = L;
			tStack.push(Node);
			pointer = pointer->leftchild();
		}
		Node = tStack.top();
		tStack.pop();
		pointer = Node.pointer;
		if (Node.tag == R) {
			visit(pointer->value);
			pointer = NULL;
		}
		else {
			Node.tag = R;
			tStack.push(Node);
			pointer = pointer->rightchild();
		}
	} while (!tStack.empty() || pointer);
}

mod
inline void BinaryTree<T>::LevelOrder(BinaryTreeNode<T>* root) {

}
*/

int main()
{
	
	return 0;
}
