#include <cstdio>

int main() {
    int hashTable[10] = {0};
    for (int i = 0; i < 10; i++) 
        scanf("%d", &hashTable[i]);
    for (int i = 1; i < 10; i++) {
        if (hashTable[i] > 0) {
            printf("%d", i);
            hashTable[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        while (hashTable[i] > 0) {
            printf("%d", i);
            hashTable[i]--;
        }
    }
    printf("\n");
    return 0;
}
