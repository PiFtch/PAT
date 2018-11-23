#include <cstdio>

long long binaryPow(long long a, long long b, long long m) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return a * binaryPow(a, b-1, m);
    else {
        long long mul = binaryPow(a, b/2, m);
        return mul * mul % m;
    }
}