#include <cstdio>
int main() {
    int n, count;
    while (scanf("%d", &n) == 1) {
        count = 0;
        while (n != 1) {
            if (n % 2 == 0)
                n /= 2;
            else
                n = (3*n+1)/2;
            count++;
        }
        printf("%d\n", count);
    }
}