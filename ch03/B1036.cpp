#include <cstdio>

int main() {
    int n;
    char c;
    int row;
    while (scanf("%d %c", &n, &c) != EOF) {
        for (int i = 0; i < n; i++)
            printf("%c", c);
        putchar('\n');
        if (n % 2 == 0)
            row = n / 2;
        else
            row = n / 2 + 1;
        for (int i = 1; i < row-1; i++) {
            printf("%c", c);
            for (int j = 0; j < n-2; j++)
                putchar(' ');
            printf("%c\n", c);
        }
        for (int i = 0; i < n; i++)
            putchar(c);
    }
}