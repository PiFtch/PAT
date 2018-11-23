#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node {
    vector<int> child;
    int layer;
} nodes[100];

int layerNum[100] = {0};

void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        layerNum[nodes[front].layer]++;
        int size = nodes[front].child.size();
        for (int i = 0; i < size; i++) {
            int child = nodes[front].child[i];
            nodes[child].layer = nodes[front].layer + 1;
            q.push(child);
        }
    }
}

int n, m;
int main() {
    scanf("%d%d", &n, &m);
    int id, k, child;
    for (int i = 1; i <= m; i++) {
        scanf("%2d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%2d", &child);
            nodes[id].child.push_back(child);
        }
    }
    int root = 1;
    nodes[root].layer = 1;
    levelOrder(root);
    int max = 0, maxIndex = 0;
    for (int i = 1; i <= n; i++) {
        if (layerNum[i] > max) {
            max = layerNum[i];
            maxIndex = i;
        }
    }
    printf("%d %d\n", max, maxIndex);
}