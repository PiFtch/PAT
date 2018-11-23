#include <algorithm>
#include <cstdio>

using namespace std;

struct node {
    int x, y;
};
bool cmp(int a, int b) {
    return a > b;
}

bool cmpNode(node a, node b) {
    if (a.x != b.x)
        return a.x > b.x;
    else
        return a.y < b.y;
}
int main() {
    int a[6] = {9,4,2,5,6,-1};
    sort(a, a+4, cmp);
    for (int i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
    sort(a, &a[5]+1, cmp);
    for (int i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');

    char ch[5] = {'k','l','a','t','p'};
    sort(ch, ch+5, cmp);
    for (int i = 0; i < 5; i++)
        printf("%c ", ch[i]);
    putchar('\n');

    node ssd[10] = {{0,0}};
    ssd[0].x = 2; ssd[0].y = 2;
    ssd[1].x = 1; ssd[1].y = 3;
    ssd[2].x = 3; ssd[2].y = 1;
    ssd[3].x = 2; ssd[3].y = 1;
    printf("%d %d", ssd[3].x, ssd[3].y);
    putchar('\n');
    sort(ssd, ssd+4, cmpNode);
    for (int i = 0; i < 4; i++) {
        printf("%d %d\n", ssd[i].x, ssd[i].y);
    }
}