#include <cstdio>
#include <cmath>
using namespace std;
struct fraction {
    long long up, down;
};

long long _abs64(long long a) {
    if (a > 0)
        return a;
    else 
        return -a;
}
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

fraction reduce(fraction frac) {
    if (frac.down < 0) {
        frac.down = -frac.down;
        frac.up = -frac.up;
    }
    if (frac.up == 0)
        frac.down = 1;
    else {
        long long d;
        if (_abs64(frac.up) > _abs64(frac.down)) {
            d = gcd(frac.up, frac.down);
        } else {
            d = gcd(frac.down, frac.up);
        }
        frac.up /= d;
        frac.down /= d;
    }
    return frac;
}

int main() {
    int n; long long up, down;
    fraction frac, sum;
    sum.up = 0; sum.down = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld/%lld", &frac.up, &frac.down);
        sum.up = sum.up * frac.down + frac.up * sum.down;
        sum.down = sum.down * frac.down;
        sum = reduce(sum);
    }
    // printf("%lld/%lld\n", sum.up. sum.down);
    if (sum.down == 1)
        printf("%lld\n", sum.up);
    else {
        long long integer = sum.up / sum.down;
        if (integer != 0) {
            printf("%lld ", integer);
            printf("%lld/%lld\n", _abs64(sum.up) % sum.down, sum.down);
        } else {
            printf("%lld/%lld\n", sum.up, sum.down);
        }
    }
}