#include <cstdio>


struct node {
    char ch;
    int next;
    bool flag;
} letters[100010];


int main() {
    int first1, first2, total;
    int addr;
    scanf("%d%d%d", &first1, &first2, &total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &addr);
        scanf(" %c %d", &letters[addr].ch, &letters[addr].next);
    }

    int p = first1;
    while (p != -1) {
        letters[p].flag = true;
        p = letters[p].next;
    }
    p = first2;
    while (p != -1) {
        if (letters[p].flag)
            break;
        letters[p].flag = true;
        p = letters[p].next;
    }
    if (p != -1)
        printf("%05d\n", p);
    else
        printf("-1\n");
}