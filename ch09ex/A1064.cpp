#include<cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int CBT[1010];

int n, temp;
int arr[1010] = {0};
int index = 0;
void inOrder(int root) {
    if (root > n)
        return;
    inOrder(root * 2);
    CBT[root] = arr[index++];
    inOrder(root * 2 + 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    inOrder(1);
    for (int i = 1; i <= n; i++) {
        printf("%d", CBT[i]);
        if (i < n)
            printf(" ");
    }
}