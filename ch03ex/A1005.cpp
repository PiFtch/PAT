/*
1005 Spell It Right（20 分）

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.
Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (≤10​100​​).
Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.
Sample Input:

12345

Sample Output:

one five

*/
#include <cstdio>

int main() {
    int num[110];
    int sum = 0;
    int i = 0;
    while (scanf("%1d", &num[i]) != EOF) {
        sum += num[i++];
    }
    if (sum == 0) {
        printf("zero");
        return 0;
    }
    int ans[110];
    int j = 0;
    while (sum != 0) {
        ans[j++] = sum % 10;
        sum /= 10;
    }
    j--;
    while (j >= 0) {
        switch (ans[j]) {
            case 0: printf("zero"); break;
            case 1: printf("one"); break;
            case 2: printf("two"); break;
            case 3: printf("three"); break;
            case 4: printf("four"); break;
            case 5: printf("five"); break;
            case 6: printf("six"); break;
            case 7: printf("seven"); break;
            case 8: printf("eight"); break;
            case 9: printf("nine"); break;
            default: break;
        }
        if (j != 0)
            printf(" ");
        j--;
    }
}