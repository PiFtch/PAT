#include <cstdio>
#include <vector>
using namespace std;
const int MAXV = 1000;
const int INF = 100000000;
struct node {
    int v, dis;
};
vector<node> adj[MAXV];
int n;
int d[MAXV];
bool vis[MAXV] = {false};
int pre[MAXV];
void Dijkstra(int s) {
    fill(d, d+MAXV, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].v;
            if (!vis[v] && d[u] + adj[u][j].dis < d[v]) {
                d[v] = d[u] + adj[u][j].dis;
                pre[v] = u;
            }
        }
    }
}
void DFS(int s, int v) {
    if (v == s) {
        printf("%d", v);
        return;
    }
    DFS(s, pre[v]);
    printf("%d ", v);
}