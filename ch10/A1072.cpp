#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXV = 1020;
const int INF = 10000000;
int graph[MAXV][MAXV];
int dis[MAXV];
bool vis[MAXV];
int N, M, K, D;

void dijkstra(int s) {
    // for (int i = 1; i <= N; i++)
    //     if (vis[i])
    //         printf("%d visited\n", i);
    //     else
    //         printf("%d not visited\n", i);
    fill(dis, dis+MAXV, INF);
    dis[s] = 0;
    for (int i = 0; i < N+M; i++) {
        int u = -1, min = INF;
        for (int j = 1; j <= N+M; j++) {
            // printf("%d: dis: %d\n", j, dis[j]);
            if (!vis[j] && dis[j] < min) {
                // printf("find new min %d\n", dis[j]);
                min = dis[j];
                u = j;
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 1; v <= N+M; v++) {
            if (!vis[v] && graph[u][v] != INF) {
                if (dis[u] + graph[u][v] < dis[v]) {
                    dis[v] = dis[u] + graph[u][v];
                }
            }
        }
    }
}

int main() {
    fill(graph[0], graph[0]+MAXV*MAXV, INF);
    scanf("%d%d%d%d", &N, &M, &K, &D);
    int p1, p2, dist;
    char str1[10], str2[10];
    for (int i = 0; i < K; i++) {
        scanf("%s%s%d", str1, str2, &dist);
        if (str1[0] == 'G') {
            p1 = atoi(&str1[1]) + N;
        } else {
            p1 = atoi(str1);
        }
        if (str2[0] == 'G') {
            p2 = atoi(&str2[1]) + N;
        } else {
            p2 = atoi(str2);
        }
        graph[p1][p2] = graph[p2][p1] = dist;
    }
    int ansID = -1;
    double ansDis = -1, ansAvg = INF;
    for (int i = 1; i <= M; i++) {
        memset(vis, false, sizeof(vis));
        dijkstra(N+i);
        // printf("G%d done\n", i);
        double min = INF;
        double sum = 0;
        // printf("Now find minDistance\n");
        for (int j = 1; j <= N; j++) {
            if (dis[j] > D) {
                min = -1;
                // printf("%d: %d further than D, break\n", j, dis[j]);
                break;
            }
            sum += (double)dis[j];
            // printf("update sum: %lf\n", sum);
            if (dis[j] < min) {
                min = dis[j];
                // printf("update min: %lf\n", min);
            }
        }
        if (min == -1)
            continue;
        if (min > ansDis) {
            // printf("UPDATE ANSDIS %lf\n", min);
            ansID = i;
            ansDis = min;
            ansAvg = sum / (double)N;
            // printf("%lf\n", ansDis);
        } else if (min == ansDis && sum / (double)N < ansAvg) {
            ansID = i;
            ansAvg = sum / (double)N;
        }
        // printf("ansID: %d ansDis: %lf ansAvg: %lf\n", ansID, ansDis, ansAvg);
    }
    if (ansID == -1) {
        printf("No Solution\n");
    } else {
        printf("G%d\n", ansID);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }
}