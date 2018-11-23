/*
1023 Have Fun with Numbers（20 分）

Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.
Input Specification:

Each input contains one test case. Each case contains one positive integer with no more than 20 digits.
Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.
Sample Input:

1234567899

Sample Output:

Yes
2469135798

*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct bign {
    int d[40];
    int len;
    bign() {
        fill(d, d+40, 0);
        len = 0;
    }
};

int flag[10] = {0};

int main() {
    char s[30];
    scanf("%s", s);
    bign num;
    num.len = strlen(s);
    for (int i = 0; i < num.len; i++) {
        num.d[i] = s[num.len - i - 1] - '0';
        flag[num.d[i]]++;
    }
    // for (int i = 0; i < num.len; i++)
    //     printf("%d", num.d[i]);
    int c = 0, tempProduct = 0;
    bool tag = true;
    bign product;
    for (int i = 0; i < num.len; i++) {
        tempProduct = num.d[i] * 2 + c;
        product.d[i] = tempProduct % 10;
        c = tempProduct / 10;
        if (flag[product.d[i]] > 0) {
            flag[product.d[i]]--;
        } else {
            tag = false;
        }
    }
    if (c != 0) {
        product.len = num.len + 1;
        product.d[num.len] = c;
    } else {
        product.len = num.len;
    }
    if (tag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (int i = product.len - 1; i >= 0; i--)
        printf("%d", product.d[i]);
}