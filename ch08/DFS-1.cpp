#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100;
int n, k, x, maxSquSum = -1, A[maxn];
vector<int> temp, ans;

void DFS(int index, int nowK, int sum, int squSum) {
    if (nowK == k && sum == x) {
        if (squSum > maxSquSum) {
            maxSquSum = squSum;
            ans = temp;
        }
        return;
    }

    if (index == n || nowK > k || sum > x)
        return;

    temp.push_back(A[index]);
    DFS(index+1, nowK+1, sum+A[index], squSum + A[index]*A[index]);
    temp.pop_back();

    DFS(index+1, nowK, sum, squSum);
}

int main() {
    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    DFS(0,0,0,0);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
        printf("%d ", *it);
}