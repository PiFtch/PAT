#include <cstdio>
int bets[100010];
int hash[10001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bets[i]);
        hash[bets[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (hash[bets[i]] == 1) {
            printf("%d\n", bets[i]);
            return 0;
        }
    }
    printf("None\n");
}