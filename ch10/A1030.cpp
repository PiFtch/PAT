#include <cstdio>
#include <vector>
// #include <algorithm>
using namespace std;
const int MAXV = 500;
const int INF = 100000000;
int graph[MAXV][MAXV];
int costMatrix[MAXV][MAXV];
int dis[MAXV];
int vis[MAXV];
int num[MAXV];
vector<int> pre[MAXV];
vector<int> path, tempPath;
int n, m, s, d;

void Dijkstra(int s) {
    fill(dis, dis+MAXV, INF);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && graph[u][v] != INF) {
                if (dis[u] + graph[u][v] < dis[v]) {
                    dis[v] = dis[u] + graph[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + graph[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int minCost = INF;
void DFS(int v) {
    if (v == s) {
        tempPath.push_back(v);
        int tempCost = 0;
        for (int i = tempPath.size() - 1; i > 0; i--) {
            int id = tempPath[i], idNext = tempPath[i-1];
            tempCost += costMatrix[id][idNext];
        }
        if (tempCost < minCost) {
            minCost = tempCost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}
int main() {
    fill(graph[0], graph[0] + MAXV * MAXV, INF);
    fill(costMatrix[0], costMatrix[0] + MAXV * MAXV, INF);
    scanf("%d%d%d%d", &n, &m, &s, &d);
    int c1, c2, dist, cost;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &c1, &c2, &dist, &cost);
        graph[c1][c2] = graph[c2][c1] = dist;
        costMatrix[c1][c2] = costMatrix[c2][c1] = cost;
    }
    Dijkstra(s);
    DFS(d);
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", dis[d], minCost);
}