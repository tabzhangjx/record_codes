#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;
const int maxn = 1e5;
struct edge {
	int u, v, w;
};
vector<edge>G[maxn];
void add(int u, int v, int w) {
	G[u].push_back((edge) { u, v, w });
}
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>>q;
int d[maxn], vis[maxn];
int s, t, n, m;
void dijk() {
	memset(d, 0x7f, sizeof(d));
	d[s] = 0;
	q.push(pii(d[s], s));
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) {
			continue;
		}
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].v, w = G[u][i].w;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push(pii(d[v], v));
			}
		}
		vis[u] = 1;

	}
	printf("%d\n", d[t]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	s = 1; t = n;
	dijk();
	return 0;
}