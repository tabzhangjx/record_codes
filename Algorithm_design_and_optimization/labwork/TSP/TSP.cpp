#include <iostream>
using namespace std;

int n = 0;
int T = 0;
int edges[1002][1002];

bool *visited = new bool[n];
int *mins = new int[n];

int record_num = 0;//number of vertex
int record_sum = 0;//whole value
int *record_vertex = new int[n];//order of vertaxs

int num = 0;
int sum = INT_MAX;
int *vertex = new int[n];

void Copy() {
	sum = record_sum;
	for (int i = 0; i<n; i++) {
		vertex[i] = record_vertex[i];
	}
}

bool judge() {
	int temp = 0;
	for (int i = 0; i<n; i++) {
		temp += mins[i];
	}
	for (int i = 0; i<record_num; i++) {
		temp -= mins[record_vertex[i]];
	}
	if (record_sum + temp>sum) {
		return true;
	}
	else {
		return false;
	}
}

void search() {
	for (int i = 0; i < n; i++) {
		if (record_num == 0) {
			record_vertex[record_num] = i + 1;
			record_num++;
			visited[i] = 1;
			search();
			visited[i] = 0;
			record_num--;
			record_vertex[record_num] = -1;
		}
		else {
			if ((edges[record_vertex[record_num - 1] - 1][i]) > 0 && !visited[i]) {
				record_vertex[record_num] = i + 1;
				record_sum += edges[record_vertex[record_num - 1] - 1][i];
				record_num++;
				visited[i] = 1;
				if (judge()) {
					return;
				}//cut branch
				if (record_num == n) {
					Copy();
					return;
				}
				else {
					search();
					visited[i] = 0;
					record_num--;
					record_sum -= edges[record_vertex[record_num - 1] - 1][i];
					record_vertex[record_num] = -1;
				}
			}
		}
	}

}
int main() {
	cin >> n >> T;
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
		record_vertex[i] = -1;
		vertex[i] = -1;
		for (int j = 0; j < n; j++) {
			edges[i][j] = -1;
		}
	}
	int a, b;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		cin >> edges[a - 1][b - 1];
	}

	for (int i = 0; i < n; i++) {
		mins[i] = NULL; //nullptr
		for (int j = 0; j < n; j++) {
			if ((mins[i] > edges[i][j] || mins[i] == NULL) && edges[i][j] > 0) {
				mins[i] = edges[i][j];
			}
		}
	}

	search();
	for (int i = 0; i < n; i++) {
		cout << vertex[i] << " -> ";
	}

	delete[]visited;
	delete[]mins;
	delete[]record_vertex;
	delete[]vertex;
	return 0;
}