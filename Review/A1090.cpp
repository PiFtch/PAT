#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
struct node {
	double price;
	vector<int> child;
}nodes[100010];
int n; double p, r;
double multiplier;
double maxPrice = 0.0;
void bfs(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (nodes[front].price > maxPrice)
			maxPrice = nodes[front].price;
		for (int i = 0; i < nodes[front].child.size(); i++) {
			int child = nodes[front].child[i];
			nodes[child].price = nodes[front].price * multiplier;
			q.push(child);
		}
	}
}
int maxDepth = 0;
int num = 0;
void dfs(int root, int depth) {
	if (nodes[root].child.empty()) {
		if (depth > maxDepth) {
			maxDepth = depth;
			num = 1;
		} else if (depth == maxDepth) {
			num++;
		}
		return;
	}
	for (int i = 0; i < nodes[root].child.size(); i++) {
		int child = nodes[root].child[i];
		nodes[child].price = nodes[root].price * multiplier;
		dfs(child, depth + 1);
	}
}

int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	multiplier = 1 + r / 100;
	int temp, root;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (temp == -1) {
			root = i;
			nodes[root].price = p;
		} else {
			nodes[temp].child.push_back(i);
		}
	}
	/*
	bfs(root);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (nodes[i].price == maxPrice)
			count++;
	}
	printf("%.2lf %d", maxPrice, count);
	*/
	dfs(root, 1);
	printf("%.2lf %d\n", p * pow(multiplier, maxDepth - 1), num);
}
