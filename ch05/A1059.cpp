#include <cstdio>
#include <cmath>
struct factor {
    int x, cnt;
} factors[20];
long prime[100010];
bool isPrime(long int n) {
    if (n <= 1) {
        return false;
    }
    long int sqr = (long int)sqrt(n * 1.0);
    for (long int i = 2; i <= sqr; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    long int n;
    scanf("%ld", &n);
    printf("%ld=", n);
    if (n == 1)
        printf("1");
    int pNum = 0;
    for (int i = 2; i < 100010; i++) {
        if (isPrime(i)) {
            prime[pNum++] = i;
        }
    }
    int pFactor = 0;
    long sqr = (long)sqrt(n * 1.0);
    for (int i = 0; i < pNum && prime[i] <= sqr; i++) {
        long num = prime[i];
        if (n % num == 0) {
            factors[pFactor].x = num;
            factors[pFactor].cnt = 1;
            n /= num;
            while (n % num == 0) {
                factors[pFactor].cnt++;
                n /= num;
            }
            pFactor++;
        }
    }
    if (n != 1) {
        factors[pFactor].x = n;
        factors[pFactor].cnt = 1;
        pFactor++;
    }
    for (int i = 0; i < pFactor; i++) {
        printf("%d", factors[i].x);
        if (factors[i].cnt > 1) {
            printf("^%d", factors[i].cnt);
        }
        if (i < pFactor - 1)
            printf("*");
    }
}