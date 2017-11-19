#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct nodeinf {
	int numsons;
	int *sons;
	bool visited;
};
class cmp {
public:
	bool operator()(Node *x, Node *y) { return true; };
};
priority_queue <Node*, vector<Node*>, cmp> Search;

class Node {
public:
	Node *parent;
	int num_sons;
	Node** sons;
	bool visited;
	Node(Node *c) { parent = c; num_sons = 0; sons = NULL; visited = 0; };
	~Node() {};
	void Buildnodes(nodeinf *c, int i);
	void dfs();
};

void Node::dfs() {
	Search.push(this);
}
void Node::Buildnodes(nodeinf *c, int i) {
	this->num_sons = c[i].numsons;
	sons = new Node*[num_sons];
	for (int j = 0; j < c[i].numsons; j++) {
		sons[j] = new Node(this);
		sons[j]->Buildnodes(c, c->sons[j]);
	}
}

class Commontree {
public:
	Node *root;
	Commontree(Node *c) { root = c; };
	Commontree() { delete root; };
	void DFS();
};

void Commontree::DFS() {

}
int main() {
	int n = 0;
	cin >> n;
	nodeinf *nodes = new nodeinf[n];
	for (int i = 0; i < n; i++) {
		nodes[i].visited = false;
		cin >> nodes[i].numsons;
		if (nodes[i].numsons == 0) {
			nodes[i].sons = NULL;
		}
		else {
			nodes[i].sons = new int[nodes[i].numsons];
		}
		for (int j = 0; j < nodes[i].numsons; j++) {
			cin >> nodes[i].sons[j];
		}
	}
	for (int i = 0; i < n; i++) {
		delete[]nodes[i].sons;
	}
	delete[]nodes;
	return 0;
}
