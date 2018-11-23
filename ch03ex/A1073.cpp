/*
1073 Scientific Notation（20 分）

Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9].[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.
Input Specification:

Each input contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.
Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros.
Sample Input 1:

+1.23400E-03

Sample Output 1:

0.00123400

Sample Input 2:

-1.2E+10

Sample Output 2:

-12000000000

*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int main() {
    char str[10010];
    char num[10010];
    // gets(str);
    scanf("%s", str);
    // int len = strlen(str);
    char sign = str[0];
    if (sign == '-')
        printf("-");
    // printf("%c", str[1]);
    num[0] = str[1];
    int i;
    int count = 1;
    for (i = 3; str[i] != 'E'; i++) {
        num[i-2] = str[i];
        count++;
    }
    /*
    while (str[i] != 'E') {
        printf("%c", str[i++]);
        count++;
    }
    */
    int posE = i;
    char expSign = str[posE + 1];
    int exp = atoi(str+posE+2);
    if (expSign == '+') {
        int j = 0;
        for (; j <= exp && j < count; j++) {
            printf("%c", num[j]);
        }
        if (j <= exp && j >= count) {
            for (; j <= exp; j++)
                printf("0");
        } else if (j > exp && j < count) {
            printf(".");
            for (; j < count; j++) {
                printf("%c", num[j]);
            }
        }
    } else {
        for (int j = 0; j < exp; j++) {
            printf("0");
            if (j == 0)
                printf(".");
        }
        // printf(".");
        for (int j = 0; j < count; j++) {
            printf("%c", num[j]);
        }
    }
}