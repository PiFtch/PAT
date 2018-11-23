#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*
struct Edge {
    int v;
    int weight;
};
vector<int> cities[505];
int teams[505] = {0};
int d[505];
bool vis[505];
int n, m, s, t;



int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < n; i++)
        scanf("%d", &teams[i]);
    int c1, c2, l;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &c1, &c2, &l);
        cities[c1].push_back
    }
}
*/
const int MAXV = 505;
const int INF = 100000000;
int graph[MAXV][MAXV];
int weight[MAXV];
int d[MAXV];
int num[MAXV] = {0};    // number of paths
int w[MAXV] = {0};  // sum of weight
bool vis[MAXV] = {false};
int n, m, s, t;

void Dijkstra(int s) {
    fill(d, d+MAXV, INF);
    d[s] = 0;
    num[s] = 1;
    w[s] = weight[s];
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && graph[u][j] != INF) {
                if (d[u] + graph[u][j] < d[j]) {
                    d[j] = d[u] + graph[u][j];
                    w[j] = w[u] + weight[j];
                    num[j] = num[u];
                } else if (d[u] + graph[u][j] == d[j]) {
                    num[j] += num[u];
                    if (w[u] + weight[j] > w[j]) {
                        w[j] = w[u] + weight[j];
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }
    fill(graph[0], graph[0] + MAXV * MAXV, INF);
    int c1, c2, l;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &c1, &c2, &l);
        graph[c1][c2] = graph[c2][c1] = l;
    }
    Dijkstra(s);
    printf("%d %d\n", num[t], w[t]);
}