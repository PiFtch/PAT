#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 210;
const int INF = 100000000;
int cost[maxn][maxn];
int weight[maxn];
bool vis[maxn] = {false};
int dis[maxn];
vector<int> pre[maxn];

map<string, int> stoi;
map<int, string> itos;
vector<int> tempPath, ans;
int n, k;

int index = 1;
int change(string str) {
	if (stoi.find(str) != stoi.end()) {
		return stoi[str];
	} else {
		stoi[str] = index;
		itos[index] = str;
		return index++;
	}
}

void dijkstra(int s) {
	fill(dis, dis+maxn, INF);
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, min = INF;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (!vis[v] && cost[u][v] != INF) {
				int dist = cost[u][v] + dis[u];
				if (dist < dis[v]) {
					dis[v] = dist;
					pre[v].clear();
					pre[v].push_back(u);
				} else if (dist == dis[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

int maxTotalWeight = -1, avgWeight = -1;
int numOfPaths = 0;
void dfs(int v) {
	if (v == 0) {
		tempPath.push_back(v);
		numOfPaths++;
		int total = 0, avg = 0;
		int num = tempPath.size() - 1;
		for (int i = tempPath.size() - 2; i >= 0; i--) {
			int id = tempPath[i];
			total += weight[id];
			avg += weight[id] / num;
		}
		if (total > maxTotalWeight) {
			maxTotalWeight = total;
			avgWeight = avg;
			ans = tempPath;
		} else if (total == maxTotalWeight) {
			if (avg > avgWeight) {
				avgWeight = avg;
				ans = tempPath;
			}
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	tempPath.pop_back();
}

int main() {
	string str1, str2;
	cin >> n >> k >> str1;
	stoi[str1] = 0;
	itos[0] = str1;
	int w, c;
	for (int i = 1; i < n; i++) {
		cin >> str1 >> w;
		int id = change(str1);
		weight[id] = w;
	}
	fill(cost[0], cost[0] + maxn * maxn, INF);
	for (int i = 0; i < k; i++) {
		cin >> str1 >> str2 >> c;
		int id1 = change(str1);
		int id2 = change(str2);
		cost[id1][id2] = cost[id2][id1] = c;
	}
	dijkstra(0);
	
	int dest = stoi["ROM"];
	dfs(dest);
//	printf("%d\n", dest);
	printf("%d %d %d %d\n", numOfPaths, dis[dest], maxTotalWeight, avgWeight);
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << itos[ans[i]];
		if (i > 0) {
			cout << "->";
		}
	}
}
