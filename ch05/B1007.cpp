#include <cstdio>
#include <cmath>
bool isPrime(int n) {
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(n * 1.0);
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int prime[100010];
bool sel[100010] = {false};
int main() {
    int n, num = 0;
    scanf("%d", &n);
    int pNum = 0;
    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            prime[pNum++] = i;
        }
    }
    for (int i = 1; i < pNum; i++) {
        if (!sel[i-1] && !sel[i]) {
            if (prime[i] - prime[i-1] == 2) {
                num++;
            }
        }
    }
    printf("%d\n", num);
}
