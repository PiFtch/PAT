/*
1077 Kuchiguse（20 分）

The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

    Itai nyan~ (It hurts, nyan~)

    Ninjin wa iyada nyan~ (I hate carrots, nyan~)

Now given a few lines spoken by the same character, can you find her Kuchiguse?
Input Specification:

Each input file contains one test case. For each case, the first line is an integer N (2≤N≤100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.
Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write nai.
Sample Input 1:

3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~

Sample Output 1:

nyan~

Sample Input 2:

3
Itai!
Ninjinnwaiyada T_T
T_T

Sample Output 2:

nai

*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100][256];
int main() {
    int n, minlen = 257;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        // gets(s[i]);
        cin.get(s[i], 256);
        getchar();
        // gets_s(s[i], 256);
        // fgets(s[i], 256, stdin);
        int len = strlen(s[i]);
        if (len < minlen)
            minlen = len;
        for (int j = 0; j < len / 2; j++) {
            char temp = s[i][j];
            s[i][j] = s[i][len - 1 - j];
            s[i][len - 1 - j] = temp;
        }
    }
    int count = 0;
    for (int i = 0; i < minlen; i++) {
        char c = s[0][i];
        bool same = true;
        for (int j = 1; j < n; j++) {
            if (s[j][i] != c) {
                same = false;
                break;
            }
        }
        if (same) {
            count++;
        } else {
            break;
        }
    }
    if (count > 0) {
        while(--count >= 0) {
            printf("%c", s[0][count]);
        }
    } else {
        printf("nai");
    }
}