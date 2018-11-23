#include <cstdio>
#include <algorithm>
using namespace std;
int father[1001];
int courses[1001] = {0};
int isRoot[1001] = {0};

void init(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
}
int findFather(int x) {
    int temp1 = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (temp1 != father[temp1]) {
        int temp2 = temp1;
        temp1 = father[temp1];
        father[temp2] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n;
    scanf("%d", &n);
    init(n);
    int course, k;
    for (int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            scanf("%*c%d", &course);
            if (courses[course] == 0)
                courses[course] = i;
            Union(i, findFather(courses[course]));
        }
    }
    for (int i = 1; i <= n; i++) {
        isRoot[findFather(i)]++;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (isRoot[i] != 0)
            sum++;
    }
    printf("%d\n", sum);
    sort(isRoot+1, isRoot+n+1, cmp);
    for (int i = 1; i <= sum; i++) {
        printf("%d", isRoot[i]);
        if (i < sum)
            printf(" ");
    }
}