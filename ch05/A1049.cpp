/*
1049 Counting Ones（30 分）

The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.
Input Specification:

Each input file contains one test case which gives the positive N (≤2​30​​).
Output Specification:

For each test case, print the number of 1's in one line.
Sample Input:

12

Sample Output:

5

*/
#include <cstdio>



int main() {
    int n;
    scanf("%d", &n);
    int total = 0;
    int left, mid = 0, right = 0;
    int a = 1;
    while (n/a > 0) {
        left = n / (a * 10);
        mid = n / a % 10;
        right = n % a;

        if (mid == 0) {
            total += left * a;
        } else if (mid == 1) {
            total += left * a + right + 1;
        } else {
            total += (left + 1) * a;
        }
        a *= 10;
    }
    printf("%d\n", total);
}