#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> Adj[1010];
bool vis[1010];
int lost;
void DFS(int v) {
    if (v == lost) {
        return;
    }
    vis[v] = true;
    for (int i = 0; i < Adj[v].size(); i++) {
        if (vis[Adj[v][i]] == false)
            DFS(Adj[v][i]);
    }
}
int n, m, k;
int main() {
    scanf("%d%d%d", &n, &m, &k);
    int id1, id2;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &id1, &id2);
        Adj[id1].push_back(id2);
        Adj[id2].push_back(id1);
    }

    for (int i = 0; i < k; i++) {
        scanf("%d", &lost);
        memset(vis, false, sizeof(vis));
        int block = 0;
        for (int i = 1; i <= n; i++) {
            if (i != lost && !vis[i]) {
                DFS(i);
                block++;
            }
        }
        printf("%d\n", block - 1);
    }
}