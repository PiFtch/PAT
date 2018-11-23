#include <cstdio>
#include <vector>
using namespace std;
const int N = 100;
int n;
struct node {
    int v, w;
    node(int _v, int _w) : v(_v), w(_w) {}
};
vector<int> Adj[N];
bool vis[N] = {false};
void DFS(int u, int depth) {
    vis[u] = true;
    for (int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        if (!vis[v]) {
            DFS(v, depth+1);
        }
    }
}

void DFSTrave() {
    for (int u = 0; u < n; u++) {
        if (!vis[u])
            DFS(u, 1);
    }
}