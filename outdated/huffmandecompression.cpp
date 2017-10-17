// Huffmancompression-de-algorithm.cpp : 定义控制台应用程序的入口点。
//




//注：建树部分只有一个构造函数不同，故此部分只写该构造函数的注释
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
public:
	HuffmanTreeNode *left;
	HuffmanTreeNode *right;
	int wei;
	char elem;
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
	void addbinary(const char * a, int i);
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

inline void HuffmanTree::addbinary(const char * a, int i) {//利用DL文件头建树
	char temp = a[i];
	if (this->root == NULL) {
		this->root = new HuffmanTreeNode;
	}
	HuffmanTreeNode*curr = this->root;
	int aa = 0;
	//根据文件内容选择新建左子树节点还是右子树结点，若已有，直接移动指针；
	for (int j = i + 1; isdigit(a[j]); j++) {
		if (a[j] == '0') {
			if (curr->left != NULL) {
				curr = curr->left;
			}
			else {
				curr->left = new HuffmanTreeNode;
				curr = curr->left;
			}
		}
		else if (a[j] == '1') {
			if (curr->right != NULL) {
				curr = curr->right;
			}
			else {
				curr->right = new HuffmanTreeNode;
				curr = curr->right;
			}
		}
	}
	curr->elem = temp;
	int aaa = 0;
}

void HuffmanTree::DeleteTree(HuffmanTreeNode* root) {
	if ((root->left == NULL) && (root->right == NULL)) {
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
	fin.open("diction.txt");
	char text[200];
	char a;
	fin >> a;
	int i = 0;
	while (a != '*') {
		text[i] = a;
		i++;
		fin >> a;
	}
	text[i] = NULL;
	HuffmanTree ex;
	for (int i = 0; text[i] != '\0'; i++) {//处理文件内容，若读到字符，则调用函数，根据后面的编码新建节点
		if (isalpha(text[i])) {
			ex.addbinary(text, i);
		}
	}
	//////////////////////////////////////////
	//////////////////////////////////////////
	//////////////////////////////////////////

	fout.open("result.txt");
	void decompress(const char* a, HuffmanTreeNode* root);
	decompress("a.dat", ex.Root());
	return 0;
}

void decompress(const char* a, HuffmanTreeNode* root)
{
	HuffmanTreeNode* tempdic = root;
	int temp;
	std::ifstream fin(a, std::ios::binary);
	while (fin.read((char*)&temp, sizeof(char)))
	{
		for (int i = 0; i <= 7; i++)
		{
			if (temp & 1)
			{
				tempdic = tempdic->Right();
			}
			else
			{
				tempdic = tempdic->Left();
			}
			if (tempdic->IsLeaf())
			{
				fout << tempdic->element();
				tempdic = root;
			}
			temp = temp >> 1;
		}
	}
	fin.close();
	return;
}

