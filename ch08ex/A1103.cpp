#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int n, k, p;
int maxFacSum = -1;
vector<int> fac, ans, temp;
void DFS(int index, int nowK, int sum, int facSum) {
    if (nowK == k && sum == n) {
        if (facSum > maxFacSum) {
            ans = temp;
            maxFacSum = facSum;
        }
        return;
    }
    if (sum > n || nowK > k)
        return;
    if (index - 1 >= 0) {
        temp.push_back(index);
        DFS(index, nowK+1, sum+fac[index], facSum+index);
        temp.pop_back();
        DFS(index-1, nowK, sum, facSum);
    }
}

void init() {
    int i = 0, temp = 0;
    while (temp <= n) {
        fac.push_back(temp);
        temp = (int)pow(++i, p);
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    init();

    DFS(fac.size()-1, 0, 0, 0);
    if (maxFacSum == -1)
        printf("Impossible\n");
    else {
        printf("%d = %d^%d", n, ans[0], p);
        for (vector<int>::iterator it = ans.begin()+1; it != ans.end(); it++)
            printf(" + %d^%d", *it, p);
    }
}