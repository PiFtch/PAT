#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct bign {
    int d[1010];
    int len;
    bign() {
        fill(d, d + 1010, 0);
        len = 0;
    }
};



int main() {
    char a[1010];
    int b;
    scanf("%s %d", a, &b);
    // printf("%d\n", strlen(a));
    int pNum = strlen(a);
    bign num;
    num.len = pNum;
    for (int i = 0; i < pNum; i++) {
        num.d[i] = a[i] - '0';
    }
    // for (int i = 0; i < pNum; i++)
    //     printf("%d", num.d[i]);
    bign ans;
    ans.len = num.len;
    int pAns = 0, before = 0, dividend = 0;
    for (int i = 0; i < num.len; i++) {
        dividend = before * 10 + num.d[i];
        ans.d[i] = dividend / b;
        before = dividend % b;
    }
    while (ans.d[pAns] == 0 && pAns < ans.len) {
        pAns++;
    }
    if (pAns == ans.len)
        printf("0");
    else
        while (pAns < ans.len) {
            printf("%d", ans.d[pAns++]);
        }
    printf(" %d\n", before);
}