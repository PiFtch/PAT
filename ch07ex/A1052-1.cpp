#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
    int addr, key, next;
    bool flag;
}nodes[100010];
bool cmp(node a, node b) {
    if (!a.flag || !b.flag) {
        return a.flag && !b.flag;
    }
    return a.key < b.key;
}
/*
int main() {
    int n, first;
    scanf("%d %5d", &n, &first);
    for (int i = 0; i < n; i++) {
        scanf("%5d %d %5d", &nodes[i].addr, &nodes[i].key, &nodes[i].next);
    }
    sort(nodes, nodes+n, cmp);
    printf("%d %05d\n", n, nodes[0].addr);
    for (int i = 0; i < n; i++) {
        printf("%05d %d ", nodes[i].addr, nodes[i].key);
        if (i < n - 1)
            printf("%05d\n", nodes[i+1].addr);
        else
            printf("-1\n");
    }
}
*/
int main() {
    for (int i = 0; i < 100010; i++)
        nodes[i].flag = false;
    int addr, n, begin;
    scanf("%d %5d", &n, &begin);
    for (int i = 0; i < n; i++) {
        scanf("%5d", &addr);
        nodes[addr].addr = addr;
        scanf("%d %5d", &nodes[addr].key, &nodes[addr].next);
    }
    int count = 0, p = begin;
    while (p != -1) {
        nodes[p].flag = true;
        count++;
        p = nodes[p].next;
    }
    if (count == 0) {
        printf("0 -1");
    } else {
        sort(nodes, nodes+100010, cmp);
        printf("%d %05d\n", count, nodes[0].addr);
        for (int i = 0; i < count; i++) {
            printf("%05d %d ", nodes[i].addr, nodes[i].key);
            if (i != count - 1)
                printf("%05d\n", nodes[i+1].addr);
            else
                printf("-1\n");
        }
    }

}