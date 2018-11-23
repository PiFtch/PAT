/*
1088 Rational Arithmetic（20 分）

For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.
Input Specification:

Each input file contains one test case, which gives in one line the two rational numbers in the format a1/b1 a2/b2. The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.
Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is number1 operator number2 = result. Notice that all the rational numbers must be in their simplest form k a/b, where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output Inf as the result. It is guaranteed that all the output integers are in the range of long int.
Sample Input 1:

2/3 -4/2

Sample Output 1:

2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

Sample Input 2:

5/3 0/6

Sample Output 2:

1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

*/

#include <cstdio>
struct fraction {
    long long up, down;
};

long long abs(long long a) {
    if (a >= 0)
        return a;
    else
        return -a;
}
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else {
        return gcd(b, a % b);
    }
}
fraction reduce(fraction frac) {
    if (frac.down < 0) {
        frac.down = -frac.down;
        frac.up = -frac.up;
    }
    if (frac.up == 0) {
        frac.down = 1;
    } else {
        long long d = gcd(abs(frac.up), abs(frac.down));
        // if (abs(frac.up) > abs(frac.down)) {
        //     d = gcd(frac.up, frac.down);
        // } else {
        //     d = gcd(frac.down, frac.up);
        // }
        frac.up /= d;
        frac.down /= d;
    }
    return frac;
}

fraction add(fraction a, fraction b) {
    fraction ans;
    ans.up = a.up * b.down + b.up * a.down;
    ans.down = a.down * b.down;
    // printf("%lld/%lld\n", ans.up, ans.down);
    ans = reduce(ans);
    return ans;
}

fraction diff(fraction a, fraction b) {
    fraction ans;
    ans.up = a.up * b.down - b.up * a.down;
    ans.down = a.down * b.down;
    return reduce(ans);
}
fraction produce(fraction a, fraction b) {
    fraction ans;
    ans.up = a.up * b.up;
    ans.down = a.down * b.down;
    return reduce(ans);
}
fraction quot(fraction a, fraction b) {
    fraction ans;
    ans.up = a.up * b.down;
    ans.down = a.down * b.up;
    return reduce(ans);
}
void showFrac(fraction frac) {
    if (frac.down == 1) {
        printf("%lld", frac.up);
    } else if (abs(frac.up) > frac.down) {
        printf("%lld %lld/%lld", frac.up / frac.down, abs(frac.up) % frac.down, frac.down);
    } else {
        printf("%lld/%lld", frac.up, frac.down);
    }
}
void showResult(fraction frac) {
    if (frac.down == 0) {
        printf("Inf");
        return;
    }
    if (frac.up < 0) {
        printf("(");
        showFrac(frac);
        printf(")");
    } else {
        showFrac(frac);
    }
}
int main() {
    fraction a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    a = reduce(a); b = reduce(b);
    // printf("%lld/%lld %lld/%lld\n", a.up, a.down, b.up, b.down);
    fraction ans;
    ans = add(a, b);
    // printf("%lld/%lld\n", ans.up, ans.down);
    showResult(a); printf(" + "); showResult(b); printf(" = "); showResult(ans); printf("\n");
    ans = diff(a, b);
    showResult(a); printf(" - "); showResult(b); printf(" = "); showResult(ans); printf("\n");
    ans = produce(a, b);
    showResult(a); printf(" * "); showResult(b); printf(" = "); showResult(ans); printf("\n");
    ans = quot(a, b);
    showResult(a); printf(" / "); showResult(b); printf(" = "); showResult(ans); printf("\n");
}