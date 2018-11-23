#include <cstdio>

int friends[101];
bool flag[101];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        friends[i] = i;
        flag[i] = false;
    }
}

int getFather(int x) {
    int temp1 = x;
    while (x != friends[x]) {
        x = friends[x];
    }
    friends[temp1] = x;
    while (friends[temp1] != temp1) {
        int temp2 = temp1;
        temp1 = friends[temp1];
        friends[temp2] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = getFather(a);
    int faB = getFather(b);
    if (faA != faB) {
        friends[faA] = faB;
    }
}
int main() {
    int n, m;
    scanf("%d%d",&n, &m);
    init(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        Union(a, b);
    }
    for (int i = 1; i <= n; i++) {
        flag[getFather(i)] = true;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += flag[i];
    printf("%d\n", sum);
}