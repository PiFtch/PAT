#include <cstdio>

struct node {
    int value;
    int next;
} nodes[100010];

int main() {
    int first, n, k;
    scanf("%d%d%d", &first, &n, &k);
    int group;
    group = n / k;

    int addr;
    for (int i = 0; i < n; i++) {
        scanf("%d", &addr);
        scanf("%d %d", &nodes[addr].value, &nodes[addr].next);
    }

    int subfirst = first;
    int tail = -1;
    for (int i = 0; i < group; i++) {
        int count = 1;
        int r = subfirst;
        int q = nodes[subfirst].next;
        int p;
        if ( q != -1)
            p = nodes[q].next;
        else
            p = -1;
        // int tail = -1;
        while (count < k) {
            nodes[q].next = r;
            r = q;
            q = p;
            if (p != -1)
                p = nodes[p].next;
            else 
                p = -1;
            count++;
        }
        if (tail != -1) {
            nodes[tail].next = r;
        }
        if (i == 0)
            first = r;
        tail = subfirst;
        nodes[subfirst].next = q;
        subfirst = q;
    }

    int p = first;
    while (p != -1) {
        printf("%05d %d ", p, nodes[p].value);
        if (nodes[p].next != -1)
            printf("%05d\n", nodes[p].next);
        else
            printf("-1\n");
        p = nodes[p].next;
    }
}