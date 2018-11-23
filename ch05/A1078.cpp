#include <cstdio>
#include <cmath>
int msize, n;
int hashTable[10000];
bool flag[10000] = {false};
int hash(int n) {
    if (!flag[n % msize])
        return n % msize;

    for (int i = 1; i < msize; i++) {
        int key = (n + i * i) % msize;
        if (!flag[key]) {
            return key;
        }
    }
    return -1;
}

bool isPrime(int n) {
    if (n <= 1)
        return false;
    int sqr = (int)sqrt(n * 1.0);
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main() {
    scanf("%d%d", &msize, &n);  
    while (!isPrime(msize)) {
        msize++;
    }
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        int hashKey = hash(num);
        if (hashKey != -1) {
            printf("%d", hashKey);
            flag[hashKey] = true;
        } else {
            printf("-");
        }
        if (i != n-1) {
            printf(" ");
        }
    }
}