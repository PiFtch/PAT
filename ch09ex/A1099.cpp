#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
    int data;
    int left, right;
 } nodes[105];
int n;
int values[105];
int index = 0;
void inOrder(int root) {
    if (root == -1)
        return;
    inOrder(nodes[root].left);
    nodes[root].data = values[index++];
    inOrder(nodes[root].right);
}
void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (nodes[front].left == -1 && nodes[front].right == -1 && q.empty())
            printf("%d", nodes[front].data);
        else
            printf("%d ", nodes[front].data);
        if (nodes[front].left != -1)
            q.push(nodes[front].left);
        if (nodes[front].right != -1)
            q.push(nodes[front].right);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &nodes[i].left, &nodes[i].right);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    sort(values, values+n);
    inOrder(0);
    levelOrder(0);
}