#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node {
    bool isRetailer;
    double price;
    vector<int> child;
} nodes[100000];

double minvalue;
int n;
double p, r, multiplexer;
void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    int count = 0;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        int size = nodes[front].child.size();
        if (size == 0) {
            if (count == 0) {
                minvalue = nodes[front].price;
            }
            count++;
        }
        for (int i = 0; i < size; i++) {
            int child = nodes[front].child[i];
            nodes[child].price = nodes[front].price * multiplexer;
            q.push(child);
        }
    }
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    multiplexer = 1.0 + r / 100;
    nodes[0].price = p;
    int num, child;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num == 0) {
            nodes[i].isRetailer = true;
        } else {
            nodes[i].isRetailer = false;
            for (int j = 0; j < num; j++) {
                scanf("%d", &child);
                nodes[i].child.push_back(child);
            }
        }
    }
    levelOrder(0);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i].isRetailer && nodes[i].price == minvalue)
            count++;
    }
    printf("%.4lf %d\n", minvalue, count);
}