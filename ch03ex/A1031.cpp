#include <cstdio>
#include <cstring>
int main() {
    char str[85];
    scanf("%s", str);
    int len = strlen(str);
    int n1 = (len + 2) / 3, n2 = len - 2 * n1 + 2;
    for (int i = 0; i < n1-1; i++) {
        printf("%c", str[i]);
        for (int j = 0; j < n2 - 2; j++)
            printf(" ");
        printf("%c\n", str[len - i - 1]);
    }
    for (int i = n1 - 1; i < n1 + n2 -1; i++) {
        printf("%c", str[i]);
    }
}