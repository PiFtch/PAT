/*
1065 A+B and C (64bit)（20 分）

Given three integers A, B and C in [−2​63​​,2​63​​], you are supposed to tell whether A+B>C.
Input Specification:

The first line of the input gives the positive number of test cases, T (≤10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.
Output Specification:

For each test case, output in one line Case #X: true if A+B>C, or Case #X: false otherwise, where X is the case number (starting from 1).
Sample Input:

3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0

Sample Output:

Case #1: false
Case #2: true
Case #3: false

*/
#include <cstdio>

int main() {
    int t;
    long long a, b, c;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        // printf("%lld %lld\n", a, b);
        long long sum = a + b;
        printf("Case #%d: ", i+1);
        if (a > 0 && b > 0 && sum < 0) {
            printf("true\n");
        } else if (a < 0 && b < 0 && sum > 0) {
            printf("false\n");
        } else {
            if (sum > c) {
                printf("true\n");
            } else {
                printf("false\n");
            }
        }
    }
}