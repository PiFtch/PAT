#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 10000000;
int g[maxn][maxn];
bool vis[maxn];
int dis[maxn];
int weight[maxn];	// bikes of each station
vector<int> pre[maxn];
int Cmax, n, Sp, m;

void dijkstra(int s) {
	fill(dis, dis + maxn, INF);
	dis[s] = 0;
	for (int i = 0; i <= n; i++) {
		int u = -1, min = INF;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v <= n; v++) {
			if (!vis[v] && g[u][v] != INF) {
				if (dis[u] + g[u][v] < dis[v]) {
					dis[v] = dis[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dis[u] + g[u][v] == dis[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

vector<int> tempPath, ans;
int need = 0;
int minSend = INF;
int minRemain = INF;
void dfs(int v) {
	if (v == 0) {
		tempPath.push_back(v);
		int need = 0, remain = 0;
		for (int i = tempPath.size() - 2; i >= 0; i--) {
			int id = tempPath[i];
			if (weight[id] >= 0) {
				remain += weight[id];
			} else {
				if (weight[id] + remain >= 0) {
					remain += weight[id];
				} else {
					need = 0 - weight[id] - remain;
					remain = 0;
				}
			}
		}
		if (need < minSend) {
			minSend = need;
			minRemain = remain;
			ans = tempPath;
		} else if (need == minSend) {
			if (remain < minRemain) {
				minRemain = remain;
				ans = tempPath;
			}
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
	scanf("%d %d %d %d", &Cmax, &n, &Sp, &m);
	int t = Cmax / 2;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &weight[i]);
		weight[i] -= t;
	}
	fill(g[0], g[0] + maxn * maxn, INF);
	int time, s1, s2;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &s1, &s2, &time);
		g[s1][s2] = g[s2][s1] = time;
	}
	dijkstra(0);
//	printf("after dijkstra: dis:");
//	for (int i = 0; i <)
	dfs(Sp);
	printf("%d ", minSend);
	for (int i = ans.size()-1; i >= 0; i--) {
		printf("%d", ans[i]);
		if (i > 0)
			printf("->");
	}
	printf(" %d\n", minRemain);
}
