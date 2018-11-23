/*
1084 Broken Keyboard (20)（20 分）
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.

Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:

Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:

For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:

7_This_is_a_test
_hs_s_a_es
Sample Output:

7TI
作者: CHEN, Yue
单位: PAT联盟
时间限制: 200ms
内存限制: 64MB
代码长度限制: 16KB
*/

#include <cstdio>
#include <cstring>

int main() {
    char str1[85], str2[85];
    bool hashTable[128] = {false};
    scanf("%s\n%s", str1, str2);
    for (int i = 0; i < strlen(str2); i++) {
        if (str2[i] >= 'a' && str2[i] <= 'z') {
            str2[i] = str2[i] + ('A' - 'a');
        }
        hashTable[str2[i]] = true;
    }
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] >= 'a' && str1[i] <= 'z')
            str1[i] = str1[i] + ('A' - 'a');
        if (!hashTable[str1[i]]) {
            putchar(str1[i]);
            hashTable[str1[i]] = true;
        }
    }
}