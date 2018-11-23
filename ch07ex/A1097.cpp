#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct node {
    int address, value, next;
    int flag;   // 0 non-use  1 discarded 2 
} nodes[maxn];

bool hashTable[10001] = {false};

bool cmp(node a, node b) {
    return a.flag < b.flag;
}

int main() {
    int begin, n;
    scanf("%d%d", &begin, &n);
    int address;
    for (int i = 0; i < n; i++) {
        scanf("%d", &address);
        scanf("%d%d", &nodes[address].value, &nodes[address].next);
        nodes[address].address = address;
    }
    for (int i = 0; i < maxn; i++) {
        nodes[i].flag = 2*maxn;
    }

    int p = begin, countValid = 0, countRemoved = 0;
    while (p != -1) {
        if (!hashTable[abs(nodes[p].value)]) {
            hashTable[abs(nodes[p].value)] = true;
            nodes[p].flag = countValid++;
        } else {
            nodes[p].flag = maxn + countRemoved++;
        }
        p = nodes[p].next;
    }

    sort(nodes, nodes+maxn, cmp);
    int count = countValid + countRemoved;
    for (int i = 0; i < count; i++) {
        if (i != countValid - 1 && i != count - 1) {
            printf("%05d %d %05d\n", nodes[i].address, nodes[i].value, nodes[i+1].address);
        } else {
            printf("%05d %d -1\n", nodes[i].address, nodes[i].value);
        }
    }
}