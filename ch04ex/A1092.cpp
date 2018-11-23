#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int num[128] = {0};
    char str1[1010], str2[1010];
    bool flag = true;
    int lack = 0;
    cin.getline(str1, 1000);
    cin.getline(str2, 1000);
    int length = strlen(str1);
    for (int i = 0; i < length; i++) {
        num[str1[i]]++;
    }
    length = strlen(str2);
    for (int i = 0; i < length; i++) {
        if (num[str2[i]] > 0) {
            num[str2[i]]--;
        } else {
            flag = false;
            lack++;
        }
    }
    if (lack == 0) {
        printf("Yes %d\n", strlen(str1) - length);
    } else
        printf("No %d\n", lack);
}

/*
abcde

*/