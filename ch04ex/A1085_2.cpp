#include <cstdio>
#include <algorithm>
using namespace std;

long long num[100010];
int main() {
    int n;
    long long p;
    scanf("%d%lld", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
    }
    sort(num, num+n);

    int i = 0, j = 0;
    int maxLength = 0;
    while (i < n && j < n) {
        while (j < n && num[i] * p >= num[j]) {
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        i++;
    }
    printf("%d\n", maxLength);
    return 0;
}