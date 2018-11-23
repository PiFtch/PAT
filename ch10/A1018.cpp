#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXV = 501;
const int INF = 100000000;
int graph[MAXV][MAXV];
int numOfBikes[MAXV];
int dis[MAXV];
bool vis[MAXV] = {false};
vector<int> pre[MAXV];
int c, n, p, m;

void dijkstra(int s) {
    fill(dis, dis+MAXV, INF);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j <= n; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && graph[u][v] != INF) {
                if (dis[v] > dis[u] + graph[u][v]) {
                    dis[v] = dis[u] + graph[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[v] == dis[u] + graph[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
vector<int> tempPath, path;
int minSend = INF;
int minBack = INF;
void dfs(int v) {
    if (v == 0) {
        int tempSend = 0, tempBack = 0;
        tempPath.push_back(v);
        for (int i = tempPath.size() - 2; i >= 0; i--) {
            int id = tempPath[i];
            if (numOfBikes[id] > c/2) {
                tempBack += (numOfBikes[id] - c/2);
            } else {
                if (tempBack > c/2 - numOfBikes[id]) {
                    tempBack -= (c/2 - numOfBikes[id]);
                } else {
                    tempSend += (c/2 - numOfBikes[id] - tempBack);
                    tempBack = 0;
                }
            }
            // tempSend += (c/2 - numOfBikes[tempPath[i]]);
        }
        // printf("tempsend: %d\n", tempSend);
        if (tempSend < minSend) {
            minSend = tempSend;
            minBack = tempBack;
            path = tempPath;
        } else  if (tempSend == minSend && tempBack < minBack) {
            minBack = tempBack;
            path = tempPath;
        }
        /*
        if (tempSend >= 0) {
            if (tempSend < minSend) {
                minSend = tempSend;
                path = tempPath;
            }
        } else {
            minSend = 0;
            if (tempSend > minBack) {
                minBack = tempSend;
                path = tempPath;
            }
        }
        */
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
    fill(graph[0], graph[0]+MAXV*MAXV, INF);
    scanf("%d%d%d%d", &c, &n, &p, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &numOfBikes[i]);
    }
    int s1, s2, t;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &s1, &s2, &t);
        graph[s1][s2] = graph[s2][s1] = t;
    }
    dijkstra(0);
    // for (int i = 1; i <= n; i++) {
    //     printf("%d's pre: ", i);
    //     for (int j = 0; j < pre[i].size(); j++)
    //         printf("%d\n", pre[i][j]);
    // }
    dfs(p);
    // for (int i = 0; i < path.size(); i++)
    //     printf("%d", path[i]);
    // if (minBack == 0-INF && minSend >= 0)
    //     printf("%d ", minSend);
    // else
    //     printf("0 ");
    printf("%d ", minSend);
    for (int i = path.size()-1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0)
            printf("->");
        else
            printf(" ");
    }
    // if (minBack <= 0 && minBack != 0-INF)
    //     printf("%d\n", 0-minBack);
    // else
    //     printf("0\n");
    printf("%d\n", minBack);
}