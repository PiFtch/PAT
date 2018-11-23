#include <cstdio>
#include <algorithm>
using namespace std;

int stick[11] = {0};

int main() {
    int n, K;
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stick[i]);
    }
    sort(stick, stick+n);
    
    int left = 1, right = stick[n-1], mid;
    int maxLength = 0;
    while (left < right) {
        int k = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < n; i++) {
            k += stick[i] / mid;
        }
        if (k >= K) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    printf("%d\n", left-1);
}