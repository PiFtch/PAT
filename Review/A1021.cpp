#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10010;
vector<int> g[maxn];
bool vis[maxn] = {false};
int n;
vector<int> temp, ans;
int depth, maxHeight = -1;
void dfs(int v, int height) {
	if (vis[v])
		return;
	
	vis[v] = true;
	int size = g[v].size();
	for (int i = 0; i < size; i++) {
		if (!vis[g[v][i]]) {
			dfs(g[v][i], height + 1);
		}
	}
}

void dfs2(int v, int height) {
	if (height > maxHeight) {
		maxHeight = height;
		temp.clear();
		temp.push_back(v);
	} else if (height == maxHeight) {
		temp.push_back(v);
	}
	
	vis[v] = true;
	int size = g[v].size();
	for (int i = 0; i < size; i++) {
		if (!vis[g[v][i]]) {
			dfs2(g[v][i], height + 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	int v1, v2;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &v1, &v2);
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	int block = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
//			depth = 0;
			dfs(i, 1);
			block++;
		}
	}
	if (block > 1)
		printf("%d blocks\n", block);
	else {
		fill(vis, vis+maxn, false);
		dfs2(1, 1);
		ans = temp;
//		for (int i = 0; i < ans.size(); i++)
//			printf("%d", ans[i]);
		fill(vis, vis+maxn, false);
		dfs2(ans[0], 1);
		int size = temp.size();
		for (int i = 0; i < size; i++) {
			ans.push_back(temp[i]);
		}
		sort(ans.begin(), ans.end());
//		for (int i = 0; i < ans.size(); i++)
//			printf("%d", ans[i]);
		printf("%d\n", ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			if (ans[i] != ans[i - 1]) {
				printf("%d\n", ans[i]);
			}
		}
	}
}

