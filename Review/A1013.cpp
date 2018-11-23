#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int graph[maxn][maxn];
vector<int> g[maxn];
bool vis[maxn] = {false};
int n, m, k;
int query;
void dfs(int v) {
	if (v == query)
		return;
	vis[v] = true;
	int size = g[v].size();
	for (int i = 0; i < size; i++) {
		if (!vis[g[v][i]])
			dfs(g[v][i]);
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		vis[front] = true;
		int size = g[front].size();
		for (int i = 0; i < size; i++) {
			if (!vis[g[front][i]] && g[front][i] != query) {
				q.push(g[front][i]);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	int city1, city2;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &city1, &city2);
		g[city1].push_back(city2);
		g[city2].push_back(city1);
	}
//	int query;
	for (int i = 0; i < k; i++) {
		scanf("%d", &query);
		fill(vis, vis + maxn, false);
		int block = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && i != query) {
//				dfs(i);
				bfs(i);
				block++;
			}
		}
		printf("%d\n", block - 1);
	}
}
