#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int powers[21];
vector<int> temp, ans;
int n, k, p;
int maxFacSum = -1;
void dfs(int index, int nowK, int sum, int facSum) {
	if (nowK == k && sum == n) {
		if (facSum > maxFacSum) {
			ans = temp;
			maxFacSum = facSum;
		}
		return;
	}
	if (sum > n || nowK > k) return;
	
	if (index - 1 > 0) {
		temp.push_back(index);
		dfs(index, nowK + 1, sum + powers[index], facSum + index);
		temp.pop_back();
		dfs(index - 1, nowK, sum, facSum);
	}
}
int main() {
	scanf("%d %d %d", &n, &k, &p);
	for (int i = 1; i <= 21; i++) {
		powers[i] = pow(i * 1.0, p * 1.0);
	}
//	for (int i = 0; i < 21; i++) {
//		printf("%d ", powers[i]);
//	}
	int sqr = (int)sqrt(n * 1.0);
	dfs(sqr, 0, 0, 0);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
}
