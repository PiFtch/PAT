#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1010;
int graph[maxn][maxn];
int weight[maxn];
bool vis[maxn];
int n, k;
map<string, int> stoi;
map<int, string> itos;

struct gang {
	int head;
	int num;
}gangs[maxn];

int index = 0;
int change(string str) {
	if (stoi.find(str) != stoi.end()) {
		return stoi[str];
	}
	stoi[str] = index;
	itos[index] = str;
	return index++;
}

void dfs(int v, int &totalValue, int &head, int &member) {
	if (weight[v] > weight[head]) {
		head = v;
	}
	vis[v] = true;
	member++;
	for (int i = 0; i < index; i++) {
		if (graph[v][i] > 0) {
			totalValue += graph[v][i];
			graph[v][i] = graph[i][v] = 0;
			if (!vis[i]) {
				dfs(i, totalValue, head, member);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	string str1, str2; int time;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2 >> time;
		int id1 = change(str1);
		int id2 = change(str2);
		graph[id1][id2] += time;
		graph[id2][id1] += time;
		weight[id1] += time;
		weight[id2] += time;
	}
	int block = 0;
	int numgan = 0;
	for (int i = 0; i < index; i++) {
		if (!vis[i]) {
			int totalValue = 0, numMember = 0, head = i;
			dfs(i, totalValue, head, numMember);
			if (totalValue > k && numMember > 2) {
				block++;
				gangs[numgan].head = head;
				gangs[numgan].num = numMember;
				numgan++;
			}
		}
	}
	printf("%d\n", block);
	if (block > 0) {
		for (int i = 0; i < numgan; i++) {
			cout << itos[gangs[i].head] << ' ' << gangs[i].num << endl;
		}
	}
}
