/*
1003 我要通过！（20 分）

“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

    字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
    任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
    如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式：

每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。
输出格式：

每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。
输入样例：

8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：

YES
YES
YES
YES
NO
NO
NO
NO

*/

#include <cstdio>
#include <cstring>
// bool PAT[3] = {false};

int main() {
    int n; char str[110];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // memset(PAT, false, sizeof(PAT));
        scanf("%s", str);
        int len = strlen(str);
        int num_p = 0, num_t = 0, pos_p = -1, pos_t = -1;
        int others = 0;
        // condition 1
        for (int j = 0; j < len; j++) {
            if (str[j] == 'P') {
                num_p++;
                pos_p = j;
            } else if (str[j] == 'A') {
                // PAT[1] = true;
            } else if (str[j] == 'T') {
                num_t++;
                pos_t = j;
            } else {
                others++;
            }
        }
        if (num_p != 1 || num_t != 1 || others > 0 || pos_t - pos_p <= 1) {
            printf("NO\n");
            continue;
        }
        // end of condition 1

        // condition 2
        int x = pos_p, y = pos_t - pos_p - 1, z = len - pos_t - 1;
        if (z - x * (y - 1) == x) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}