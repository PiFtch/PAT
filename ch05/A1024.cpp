/*
1024 Palindromic Number（25 分）

A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.
Input Specification:

Each input file contains one test case. Each case consists of two positive numbers N and K, where N (≤10​10​​) is the initial numer and K (≤100) is the maximum number of steps. The numbers are separated by a space.
Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.
Sample Input 1:

67 3

Sample Output 1:

484
2

Sample Input 2:

69 3

Sample Output 2:

1353
3

*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct bign {
    int d[1000];
    int len;
    bign() {
        fill(d, d+1000, 0);
        len = 0;
    }
};

inline void show(bign num) {
    for (int i = num.len - 1; i >= 0; i--)
        printf("%d", num.d[i]);
}

bool isPalindromic(bign num) {
    int mid = num.len / 2;
    for (int i = 0; i < mid; i++) {
        if (num.d[i] != num.d[num.len - i - 1]) {
            return false;
        }
    }
    return true;
}

inline bign proc(bign num) {
    bign ans, op;
    for (int i = 0; i < num.len; i++) {
        op.d[i] = num.d[num.len - i - 1];
    }
    int c = 0, temp = 0;
    for (int i = 0; i < num.len; i++) {
        temp = num.d[i] + op.d[i] + c;
        ans.d[i] = temp % 10;
        c = temp / 10;
    }
    if (c != 0) {
        ans.len = num.len + 1;
        ans.d[num.len] = c;
    } else {
        ans.len = num.len;
    }
    return ans;
}

int main() {
    bign num;
    char s[6]; int k;
    scanf("%s %d", s, &k);
    num.len = strlen(s);
    for (int i = 0; i < num.len; i++) {
        num.d[i] = s[num.len - i - 1] - '0';
    }
    // for (int i = 0; i < num.len; i++) {
    //     printf("%d", num.d[i]);
    // }
    if (isPalindromic(num)) {
        show(num);
        printf("\n0");
        return 0;
    }
    int step;
    for (step = 1; step <= k; step++) {
        num = proc(num);
        if (isPalindromic(num)) {
            break;
        }
    }
    show(num);
    if (step > k)
        printf("\n%d", k);
    else {
        printf("\n%d", step);
    }
}