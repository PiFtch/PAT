#include <cstdio>
double a[1001], b[1001], c[1001];

int main() {
    int k1, k2, exp;
    int count = 0;
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++) {
        scanf("%d", &exp);
        scanf("%lf", &a[exp]);
        c[exp] = a[exp];
        count++;
    }
    scanf("%d", &k2);
    for (int i = 0; i < k2; i++) {
        scanf("%d", &exp);
        scanf("%lf", &b[exp]);
        c[exp] += b[exp];
        if (c[exp] == b[exp]) {
            count++;
        } else if (c[exp] == 0) {
            count--;
        }
    }
    printf("%d", count);
    for (int index = 1000; index >= 0; index--) {
        if (c[index] != 0) {
            printf(" %d %.1lf", index, c[index]);
        }
    }
    /*
    while (count > 0) {
        if (c[index] != 0) {
            printf("%d %.1lf", index, c[index]);
            count--;
            if (count != 0)
                printf(" ");
        }
        index--;
    }
    */
}