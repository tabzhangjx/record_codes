// Huffmancompression-de-algorithm.cpp : �������̨Ӧ�ó������ڵ㡣
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

//�����������Ķ���
class HuffmanTreeNode {
	friend class HuffmanTree;
private:
	//Ԫ�أ�Ȩֵ�����Һ��ӽڵ�
	HuffmanTreeNode *left;
	HuffmanTreeNode *right;
	int wei;
	char elem;
public:
	//���캯�����������
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

HuffmanTreeNode::HuffmanTreeNode(HuffmanTreeNode *l, HuffmanTreeNode *r, int weight, char element) {//����һ��Ԫ�������죻
	this->right = l;
	this->right = r;
	this->wei = weight;
	this->elem = element;
}


HuffmanTreeNode::~HuffmanTreeNode() {//������������ʵ������

}

//���������Ķ���
class HuffmanTree {
private:
	//������ڵ�
	HuffmanTreeNode*root;
public:
	//���캯�����������
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


inline HuffmanTree::HuffmanTree(HuffmanTree*l, HuffmanTree*r, int weight) {//�ϲ����Ź���������
	this->root = new HuffmanTreeNode;
	this->root->left = (l->root);
	this->root->right = (r->root);
	this->root->wei = weight;
	int a = 0;
}

void HuffmanTree::DeleteTree(HuffmanTreeNode* root) {//ɾ���ڵ㣻
	if ((root->left == NULL) && (root->right == NULL)) {
		root->~HuffmanTreeNode();
	}
	else {
		DeleteTree(root->left);
		DeleteTree(root->right);
	}
}


HuffmanTree::~HuffmanTree() {//����ɾ������㣻
	delete root;
}

//Ȩֵ�ȽϺ�������Ϊ��������غ������ر��ڵ���
class cmp {
public:
	bool operator()(HuffmanTree*x, HuffmanTree*y) { return x->weight() > y->weight(); };
};

//����Ԫ�����������ȶ��н�����������
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

typedef vector<bool>Huff_Code;//���������洢һ��Ԫ�صĹ��������룻
map <char, Huff_Code>Huff_Dic;//����map�ֵ�洢Ԫ�����Ӧ����ļ�ֵ�ԣ�
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
	//�ݹ�ʵ�ֱ���Ĵ洢��
}


int main()
{
	ostringstream texttemp;
	char temp;
	//��Դ�ļ���
	fin.open("C:\\projecttxt\\testchar2.txt");
	//��DL�ļ�ͷ������ļ���
	//�������ݣ�
	fout.open("C:\\projecttxt\\diction.txt");
	while (texttemp&&fin.get(temp)) {
		texttemp.put(temp);
	}
	string text = texttemp.str();
	char str[27] = { 'a','b','c','d','e','f','g','h','i','j' ,'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int wei[26] = { '\0' };
	for (int i = 0; i < 26; i++) {
		wei[i] = 0;
	}
	//ͳ��Ȩֵ��
	for (int i = 0; text[i] != '\0'; i++) {
		wei[text[i] - 'a']++;
	}
	int whole = 26;
	//����
	HuffmanTree *treeone = BuildHuffmanTree(str, wei, whole);
	Huff_Code cunchu;
	//�����������
	for (int i = 0; i < whole; i++) {
		Huff_Dic.insert(make_pair(str[i], 0));
	}
	HuffmanTreeNode* ex = treeone->Root();
	Huffman_Code(ex, Huff_Dic[2]);
	int a = 0;
	////////////////////////////////////////////////
	////////////////////////////////////////////////
	////////////////////////////////////////////////
	void write_diction(map<char, Huff_Code> & diction);
	write_diction(Huff_Dic);
	fout.close();
	void compress(const char*x, int n, map<char, Huff_Code> & diction);
	compress(text.c_str(), text.size(), Huff_Dic);
	////////////////////////////////////////////////
	////////////////////////////////////////////////

	return 0;
}

void write_diction(map<char, Huff_Code> & diction)
{
	for (char i = 0; i < 26; i++)
	{
		fout << (char)(i + 'a');
		vector<bool> temp(diction[(char)(i + 'a')]);
		for (int i = 0; i<temp.size(); i++)
			fout << (int)temp[i];
	}
	fout << '*';
}

void compress(const char* x, int n, map<char, Huff_Code> & diction)
{
	vector <bool> Dic[26];
	for (char i = 0; i < 26; i++)
	{
		//Dic[(int)(i - 'a')].assign( Huff_Dic[i].begin(),Huff_Dic[i].end());
		//vector<bool> temp(diction[char(i+'a')]);
		Dic[(int)i].assign(diction[char(i + 'a')].begin(), diction[char(i + 'a')].end());
	}
	std::ofstream fout("C:\\projecttxt\\a.dat", std::ios::binary);
	char a = 0;
	int temp = 1;
	int flag = 1;
	int j = 1, k = 0, tempsize = 0;
	char tempch = x[0];
	//vector<bool> Dic_temp(diction[tempch]);
	tempsize = Dic[tempch - 'a'].size();
	//tempsize = size(Dic_temp);
	int i = 0;
	for (; tempch != '\0'; i++)
	{
		if (i % 8 == 0)
		{
			if (flag)
				flag = 0;
			else
			{
				fout.write(&a, sizeof(char));
			}
			a = 0, temp = 1;
		}

		if (Dic[tempch - 'a'][k++])
			a += temp;
		temp = temp << 1;
		if (tempsize == k)
		{
			tempch = x[j++];
			k = 0;
			tempsize = Dic[tempch - 'a'].size();
		}
	}
	i--;
	fout.write(&a, sizeof(char));
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
