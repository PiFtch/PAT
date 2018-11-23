#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
bool hashTable[256] = {false};
char str1[10001], str2[10001];
int main() {
    // char str[20];
    // // fgets(str, 20, stdin);
    // cin.get(str, 20);
    // printf("%s%d\n%s", str, strlen(str), str);
    cin.get(str1, 10000);
    getchar();
    cin.get(str2, 10000);
    // printf("%d\n", strlen(str2));
    // printf("%s\n%saaa", str1, str2);
    int len1 = strlen(str1);
    for (int i = 0; i < len1; i++) {
        hashTable[str1[i]] = true;
    }
    int len2 = strlen(str2);
    for (int i = 0; i < len2; i++) {
        hashTable[str2[i]] = false;
    }
    for (int i = 0; i < len1; i++) {
        if (hashTable[str1[i]])
            putchar(str1[i]);
    }
}