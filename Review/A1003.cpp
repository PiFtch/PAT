#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 100000000;
int g[maxn][maxn];
bool vis[maxn];
int weight[maxn];
int dis[maxn];
int numOfPaths[maxn]; 
int sumOfWeight[maxn];
int n, m, c1, c2;

void dijkstra(int s) {
	fill(dis, dis+maxn, INF);
	dis[s] = 0;
	numOfPaths[s] = 1;
	sumOfWeight[s] = weight[s];
	for (int i = 0; i < n; i++) {
		int u = -1, min = INF;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dis[j] < min) {
				u = j;
				min = dis[j];
			}
		}
		
		if (u == -1)
			return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (!vis[v] && g[u][v] != INF) {
				if (dis[u] + g[u][v] < dis[v]) {
					dis[v] = dis[u] + g[u][v];
					numOfPaths[v] = numOfPaths[u];
					sumOfWeight[v] = sumOfWeight[u] + weight[v];
				} else if (dis[u] + g[u][v] == dis[v]) {
					numOfPaths[v] += numOfPaths[u];
					if (sumOfWeight[u] + weight[v] > sumOfWeight[v]) {
						sumOfWeight[v] = sumOfWeight[u] + weight[v];
					}
				}
			} 
		}
	}
}
 
int main() {
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}
	fill(g[0], g[0] + maxn * maxn, INF);
	int v1, v2, len;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &v1, &v2, &len);
		g[v1][v2] = g[v2][v1] = len;
		
	}
	dijkstra(c1);
	printf("%d %d\n", numOfPaths[c2], sumOfWeight[c2]);
}
