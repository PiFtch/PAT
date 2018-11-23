#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct node {
    double price;
    vector<int> child;
    bool isRetailer;
} nodes[100010];

int n;
double r, p, multiplexer;
double maxPrice;
void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (nodes[front].child.empty()) {
            nodes[front].isRetailer = true;
            if (q.empty())
                maxPrice = nodes[front].price;
        }
        else
            nodes[front].isRetailer = false;
        for (vector<int>::iterator it = nodes[front].child.begin(); it != nodes[front].child.end(); it++) {
            q.push(*it);
            nodes[*it].price = nodes[front].price * multiplexer;
        }
    }
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    multiplexer = 1.0 + r / 100;
    int supplier, root;
    for (int i = 0; i < n; i++) {
        scanf("%d", &supplier);
        if (supplier != -1)
            nodes[supplier].child.push_back(i);
        else
            root = i;
    }
    nodes[root].price = p;
    levelOrder(root);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i].isRetailer && nodes[i].price == maxPrice)
            count++;
    }
    printf("%.2lf %d\n", maxPrice, count);
}