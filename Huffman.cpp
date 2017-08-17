// Huffmancompression-de-algorithm.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

ifstream fin;
ofstream fout;

class HuffmanTreeNode {
	friend class HuffmanTree;
private:
	HuffmanTreeNode *left;
	HuffmanTreeNode *right;
	int wei;
	char elem;
public:
	HuffmanTreeNode() { left = right = NULL; wei = 0; };
	HuffmanTreeNode(HuffmanTreeNode *l, HuffmanTreeNode *r, int weight, char element);
	~HuffmanTreeNode();
	int weight() { return wei; };
	char& element() { return elem; };
	bool IsLeaf() { return !left && !right; };
	void setLeft(HuffmanTreeNode*b) { left = b; };
	void setRight(HuffmanTreeNode*b) { right = b; };
	HuffmanTreeNode*Left()const { return left; };
	HuffmanTreeNode*Right()const { return right; };
};

HuffmanTreeNode::HuffmanTreeNode(HuffmanTreeNode *l, HuffmanTreeNode *r, int weight, char element) {
	this->right = l;
	this->right = r;
	this->wei = weight;
	this->elem = element;
}


HuffmanTreeNode::~HuffmanTreeNode() {

}


class HuffmanTree {
private:
	HuffmanTreeNode*root;
public:
	HuffmanTree() { root = NULL; };
	HuffmanTree(char element, int weight);
	HuffmanTree(HuffmanTree*l, HuffmanTree*r, int weight);
	void DeleteTree(HuffmanTreeNode* root);
	~HuffmanTree();
	HuffmanTreeNode*Root() { return root; };
	int weight() { return root->wei; };
};


HuffmanTree::HuffmanTree(char element, int weight) {
	this->root = new HuffmanTreeNode;
	this->root->left = NULL;
	this->root->right = NULL;
	this->root->elem = element;
	this->root->wei = weight;
}


inline HuffmanTree::HuffmanTree(HuffmanTree*l, HuffmanTree*r, int weight) {
	this->root = new HuffmanTreeNode;
	this->root->left = (l->root);
	this->root->right = (r->root);
	this->root->wei = weight;
	int a = 0;
}

void HuffmanTree::DeleteTree(HuffmanTreeNode* root) {
	if ((root->left == NULL)&&(root->right == NULL)) {
		root->~HuffmanTreeNode();
	}
	else {
		DeleteTree(root->left);
		DeleteTree(root->right);
	}
}


HuffmanTree::~HuffmanTree() {
	delete root;
}


class cmp {
public:
	bool operator()(HuffmanTree*x, HuffmanTree*y) { return x->weight() > y->weight(); };
};


HuffmanTree *BuildHuffmanTree(char element[], int weight[], int n) {
	priority_queue < HuffmanTree *, vector<HuffmanTree*>, cmp> QHTree;
	for (int i = 0; i < n; i++) {
		QHTree.push(new HuffmanTree(element[i], weight[i]));
	}
	while (QHTree.size() > 1) {
		HuffmanTree*rc = QHTree.top();
		QHTree.pop();
		HuffmanTree*lc = QHTree.top();
		QHTree.pop();
		HuffmanTree*parent = new HuffmanTree(lc, rc, lc->weight() + rc->weight());
		QHTree.push(parent);
	}
	return QHTree.top();
}

typedef vector<bool>Huff_Code;
map <char, Huff_Code>Huff_Dic;
void Huffman_Code(HuffmanTreeNode*r, Huff_Code curcode) {
	if (r->IsLeaf()) {
		Huff_Dic[r->element()] = curcode;
		return;
	}
	Huff_Code lcode = curcode;
	Huff_Code rcode = curcode;
	lcode.push_back(false);
	rcode.push_back(true);
	Huffman_Code(r->Left(), lcode);
	Huffman_Code(r->Right(), rcode);
}

int main()
{
	ostringstream texttemp;
	char temp;
	fin.open("C:\\projecttxt\\testchar2.txt");
	fout.open("C:\\projecttxt\\result.txt");
	while (texttemp&&fin.get(temp)) {
		texttemp.put(temp);
	}
	string text = texttemp.str();
	char str[27] = { 'a','b','c','d','e','f','g','h','i','j' ,'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int wei[26] = { '\0' };
	for (int i = 0; i < 26; i++) {
		wei[i] = 0;
	}
	for (int i = 0; text[i] != '\0'; i++) {
		for (int j = 0; j < 26; j++) {
			if (text[i] == str[j]) {
				wei[j]++;
			}
		}
	}
	int whole = 26;
	HuffmanTree *treeone = BuildHuffmanTree(str, wei, whole);
	Huff_Code cunchu;
	for (int i = 0; i < whole; i++) {
		Huff_Dic.insert(make_pair(str[i], 0));
	}
	HuffmanTreeNode* ex = treeone->Root();
	Huffman_Code(ex, Huff_Dic[2]);
	char tempp = 'a';
	int sizee = size(Huff_Dic[tempp]);
	bool a = Huff_Dic[tempp][1];
	return 0;
}

