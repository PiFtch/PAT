#include <cstdio>
#include <cmath>
typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    ll sqr = (ll)sqrt(1.0 * n), ansI = 0, ansLen = 0;
    for (ll i = 2; i <= sqr; i++) {
        ll temp = 1, j = i;
        while (1) {
            temp *= j;
            if (n % temp != 0)
                break;
            if (j - i + 1 > ansLen) {
                ansLen = j - i + 1;
                ansI = i;
            }
            j++;
        }
    }
    if (ansLen == 0) {
        printf("1\n%lld", n);
    } else {
        printf("%lld\n", ansLen);
        for (ll i = 0; i < ansLen; i++) {
            printf("%lld", ansI + i);
            if (i < ansLen - 1)
                printf("*");
        }
    }
}