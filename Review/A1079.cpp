#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct node {
	double price;
	vector<int> child;
	double inventory;
	bool isLeaf;
}nodes[100010];
int n; double p, r, multiplier;
double total = 0.0;

void dfs(int root, int depth) {
	if (nodes[root].child.empty()) {
		nodes[root].price = p * pow(multiplier, depth);
		total += nodes[root].price * nodes[root].inventory;
		printf("LEAF: inventory: %lf price: %lf\n", nodes[root].inventory, nodes[root].price);
		return;
	}
	
	int size = nodes[root].child.size();
	for (int i = 0; i < size; i++) {
		int child = nodes[root].child[i];
		dfs(child, depth + 1);
	}
}

int main() {
//	printf("%lf %lf", nodes[5].price, nodes[5].inventory);
//	printf("%d", nodes[5].isLeaf);
	scanf("%d %lf %lf", &n, &p, &r);
	multiplier = 1 + r / 100;
	int k, child;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k == 0) {
			scanf("%lf", &nodes[i].inventory);
//			printf("k == 0")
		} else {
			for (int j = 0; j < k; j++) {
				scanf("%d", &child);
				nodes[i].child.push_back(child);
			}
		}
	}
	dfs(0, 0);
	printf("%.1lf\n", total);
}
