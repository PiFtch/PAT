#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100005;
struct node {
    int address, data, next;
    bool flag;
} nodes[maxn];

bool cmp(node a, node b) {
    if (a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main() {
    for (int i = 0; i < maxn; i++) {
        nodes[i].flag = false;
    }
    int n, begin, address;
    scanf("%d%d", &n, &begin);
    for (int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d%d", &nodes[address].data, &nodes[address].next);
        nodes[address].address = address;
    }
    int count = 0, p = begin;
    while (p != -1) {
        nodes[p].flag = true;
        count++;
        p = nodes[p].next;
    }
    if (count == 0) {
        printf("0 -1\n");
    } else {
        sort(nodes, nodes+maxn, cmp);
        printf("%d %5d\n", count, nodes[0].address);
        for (int i = 0; i < count; i++) {
            if (i != count - 1) {
                printf("%05d %d %05d\n", nodes[i].address, nodes[i].data, nodes[i+1].address);
            } else
                printf("%05d %d -1", nodes[i].address, nodes[i].data);
        }
    }
}