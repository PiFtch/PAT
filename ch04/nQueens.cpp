#include <cstdio>
#include <cmath>
const int maxn = 11;
int count = 0;
int n;
int P[maxn];    // p[i]: i represents row, value is col
bool hashTable[maxn] = {false};     // false represents no queen in col
void generate(int index) {
    if (index == n + 1) {
        count++;
        return;
    }
    for (int x = 1; x <= n; x++) {
        if (!hashTable[x]) {
            bool flag = true;
            for (int pre = 1; pre < index; pre++) {
                if (abs(pre-index) == abs(x-P[pre])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                P[index] = x;
                hashTable[x] = true;
                generate(index+1);
                hashTable[x] = false;
            }
        }
    }
}

int main() {
    n = 10;
    generate(1);
    printf("%d", count);
}