#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 510;
const int INF = 100000000;
int g[maxn][maxn], cost[maxn][maxn];
int dis[maxn];
bool vis[maxn] = {false};
vector<int> pre[maxn];

int n, m, s, d;
vector<int> tempPath, ans;

void dijkstra(int s) {
	fill(dis, dis + maxn, INF);
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, min = INF;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (!vis[v] && g[u][v] != INF) {
				int dist = dis[u] + g[u][v];
				if (dist < dis[v]) {
					dis[v] = dist;
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dist == dis[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

int minCost = INF;
void dfs(int v) {
	if (v == s) {
		tempPath.push_back(v);
		int tempCost = 0;
		for (int i = tempPath.size() - 1; i > 0; i--) {
			int c1 = tempPath[i], c2 = tempPath[i - 1];
			tempCost += cost[c1][c2];
		}
		if (tempCost < minCost) {
			minCost = tempCost;
			ans = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	tempPath.pop_back();
}

int main() {
	scanf("%d %d %d %d", &n, &m, &s, &d);
	fill(g[0], g[0] + maxn * maxn, INF);
	
	int c1, c2, dist, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &c1, &c2, &dist, &c);
		g[c1][c2] = g[c2][c1] = dist;
		cost[c1][c2] = cost[c2][c1] = c;
	}
	dijkstra(s);
	/*
	for (int i = 0; i < n; i++) {
		printf("%d ", dis[i]);
	}
	printf("\n");
	*/
	for (int i = 0; i < n; i++) {
		printf("i's pre: %d\n", pre[i].size());
	}
	
	dfs(d);
	for (int i = ans.size() - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}
	printf("%d %d\n", dis[d], minCost);
}

