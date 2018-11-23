#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct node {
    double price;
    vector<int> child;
    bool isRetailer;
    double num;
} nodes[100010];
int n;
double p, r;
double multipler;

void levelOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int i = 0; i < nodes[front].child.size(); i++) {
            int child = nodes[front].child[i];
            nodes[child].price = nodes[front].price * multipler;
            q.push(child);
        }
    }
}
int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    multipler = 1.0 + r / 100;
    int num_of_childs, child;
    double num_of_product;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num_of_childs);
        if (num_of_childs == 0) {
            scanf("%lf", &num_of_product);
            nodes[i].isRetailer = true;
            nodes[i].num = num_of_product;
        } else {
            for (int j = 0; j < num_of_childs; j++) {
                scanf("%d", &child);
                nodes[i].child.push_back(child);
                nodes[i].isRetailer = false;
            }
        }
    }
    nodes[0].price = p;
    levelOrder(0);

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        if (nodes[i].isRetailer)
            sum += nodes[i].price * nodes[i].num;
    }
    printf("%.1lf\n", sum);
}