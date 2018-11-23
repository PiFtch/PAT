#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct node {
    vector<int> child;
    int layer;
} nodes[101];
int n, m;
int layer[101] = {0};
int layerCount = 0;
void BFS(int root) {
    queue<int> q;
    q.push(root);
    nodes[root].layer = 1;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (nodes[front].layer > layerCount) {
            layerCount++;
        }
        int size = nodes[front].child.size();
        if (size == 0) {
            layer[nodes[front].layer]++;
        }
        for (int i = 0; i < size; i++) {
            int child = nodes[front].child[i];
            nodes[child].layer = nodes[front].layer + 1;
            q.push(child);
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    int id, k, child;
    for (int i = 0; i < m; i++) {
        scanf("%2d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%2d", &child);
            nodes[id].child.push_back(child);
        }
    }
    BFS(1);
    for (int i = 1; i <= layerCount; i++) {
        if (i < layerCount)
            printf("%d ", layer[i]);
        else
            printf("%d\n", layer[i]);
    }
}
