#include<iostream>
using namespace std;

int T = 0;//input of all edges
int n = 0;//num of vertex
int record_max = 0;
int *record_vertexs = new int[n];
int max = 0;
int *vertex = new int[n];
bool *visited = new bool[n];
bool edges[1002][1002];

void Copy() {
	for (int t = 0; t<record_max; t++) {
		vertex[t] = record_vertexs[t];
	}
	max = record_max;
}

bool check(int i) {
	for (int t = 0; t<record_max; t++) {
		if (edges[record_vertexs[t]][i] == 1) {
		}
		else {
			return false;
		}
	}
	return true;
}
void search_maxgroup() {
	for (int t = 0; t<n; t++) {
		if (record_max + n - t < max) {
			return;
		}
		if (check(t) && !visited[t]) {
			record_vertexs[record_max] = t + 1;
			record_max++;
			visited[t] = 1;
			if (record_max>max) {
				Copy();
			}
			search_maxgroup();
			record_max--;
			record_vertexs[record_max] = -1;
			visited[t] = 0;
		}
	}
	return;
}

int main() {
	cin >> T >> n;
	int a;
	int b;
	for (int i = 0; i<n; i++) {
		record_vertexs[i] = -1;
		vertex[i] = -1;
		visited[i] = 0;
		for (int j = 0; j<n; j++) {
			edges[i][j] = edges[j][i] = 0;
		}
	}
	for (int i = 0; i<T; i++) {
		cin >> a >> b;
		edges[a][b] = edges[b][a] = 1;
	}
	search_maxgroup();
	cout << max << endl;
	for (int t = 0; t<max; t++) {
		cout << t << ": " << vertex[t] << endl;
	}
	int mmm = 0;
	//delete []record_vertexs;
	//delete []vertex;
	//delete []visited;
	return 0;
}