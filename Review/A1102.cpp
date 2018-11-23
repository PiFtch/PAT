#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
struct node {
	int left, right;
}nodes[100];
bool isChild[100] = {false};
int n;

void level(int root) {
	if (root == -1)
		return;
	queue<int> q;
	q.push(root);
	int count = 0;
	while (!q.empty()) {
		
		int front = q.front();
		q.pop();
		printf("%d", front);
		count++;
		if (count < n)
			printf(" ");
		if (nodes[front].left != -1)
			q.push(nodes[front].left);
		if (nodes[front].right != -1)
			q.push(nodes[front].right);
	}
}
int count = 0;
void in(int root) {
	if (root == -1)
		return;
		
	if (nodes[root].left != -1)
		in(nodes[root].left);
	printf("%d", root);
	count++;
	if (count < n)
		printf(" ");
	if (nodes[root].right != -1)
		in(nodes[root].right);
}
int main() {
	scanf("%d", &n);
	char str1[10], str2[10];
	int left, right;
	for (int i = 0; i < n; i++) {
		scanf("%s %s", str1, str2);
		if (strcmp(str1, "-") == 0)
			right = -1;
		else {
			right = atoi(str1);
			isChild[right] = true;
		}
		if (strcmp(str2, "-") == 0)
			left = -1;
		else {
			left = atoi(str2);
			isChild[right] = true;
		}
		nodes[i].left = left; nodes[i].right = right;
		printf("%d %d\n", left, right);
	}
	int root = -1;
	for (int i = 0; i < n; i++) {
		if (!isChild[i]) {
			root = i;
			break;
		}
	}	
	level(root);
	printf("\n");
	in(root);
}
