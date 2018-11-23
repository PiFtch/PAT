#include <cstdio>
#include <cstring>
const int maxn = 1010;
int hashTable[80] = {0}, miss = 0;

int change(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 36;
}

int main() {
    char whole[maxn], target[maxn];
    fgets(whole, maxn, stdin);
    fgets(target, maxn, stdin);
    int len1 = strlen(whole);
    int len2 = strlen(target);
    whole[len1-1] = '\0';
    target[len2-1] = '\0';

    for (int i = 0; i < len1; i++) {
        int id = change(whole[i]);
        hashTable[id]++;
    }
    for (int i = 0; i < len2; i++) {
        int id = change(target[i]);
        hashTable[id]--;
        if (hashTable[id] < 0)
            miss++;
    }
    if (miss > 0)
        printf("No %d\n", miss);
    else
        printf("Yes %d\n", len1 - len2);
}