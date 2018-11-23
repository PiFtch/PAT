#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int weight;
	vector<int> child;
}nodes[110];

int n, m, s;
vector<int> path;

bool cmp(int a, int b) {
	return nodes[a].weight > nodes[b].weight;
}

void dfs(int root, int sum) {
	if (sum > s)
		return;
	if (nodes[root].child.empty()) {
		if (sum == s) {
			int size = path.size();
			for (int i = 0; i < size; i++) {
				printf("%d", path[i]);
				if (i < size - 1)
					printf(" ");
				else
					printf("\n");
			}
		}
		return;
	}
	
	int size = nodes[root].child.size();
	for (int i = 0; i < size; i++) {
		int child = nodes[root].child[i];
		path.push_back(nodes[child].weight);
		dfs(child, sum + nodes[child].weight);
		path.pop_back();
//		dfs(child, sum);
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &nodes[i].weight);
	int id, k, child;
	for (int i = 0; i < m; i++) {
		scanf("%2d %d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%2d", &child);
			nodes[id].child.push_back(child);
			sort(nodes[id].child.begin(), nodes[id].child.end(), cmp);
		}
	}
	path.push_back(nodes[0].weight);
	dfs(0, nodes[0].weight);
	
}
