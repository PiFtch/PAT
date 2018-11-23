#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
	int data;
	int left, right;
}nodes[110];
int inList[110];
int n;

int index = 0;
void inOrder(int root) {
	if (root == -1)
		return;
		
	inOrder(nodes[root].left);
	nodes[root].data = inList[index++];
	inOrder(nodes[root].right);
}
void level(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		printf("%d ", nodes[front].data);
		if (nodes[front].left != -1)
			q.push(nodes[front].left);
		if (nodes[front].right != -1)
			q.push(nodes[front].right);
	}
}
int main() {
	scanf("%d", &n);
//	int left, right;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &nodes[i].left, &nodes[i].right);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", inList+i);
	sort(inList, inList + n);
	inOrder(0);
	level(0);
}
