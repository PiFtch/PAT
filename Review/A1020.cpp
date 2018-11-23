#include <cstdio>
#include <queue>
using namespace std;
struct node {
	int value;
	node *left, *right;
};
int n;
int post[30], in[30];

node *create(int postL, int postR, int inL, int inR) {
	if (postL > postR || inL > inR) {
		return NULL;
	}
	
	node *root = new node;
	root->value = post[postR];
	int i;
	for (i = inL; i <= inR; i++) {
		if (in[i] == post[postR])
			break;
	}
	int numLeft = i - inL;
	root->left = create(postL, postL + numLeft - 1, inL, i - 1);
	root->right = create(postL + numLeft, postR - 1, i + 1, inR);
	return root;	
}
void level(node *root) {
	int count = 0;
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node *front = q.front();
		q.pop();
		printf("%d", front->value);
		count++;
		if (count < n)
			printf(" ");
		if (front->left != NULL)
			q.push(front->left);
		if (front->right != NULL)
			q.push(front->right);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	printf("MARK1\n");
	node *root = create(0, n - 1, 0, n - 1);
	printf("MARK\n");
	level(root);
} 
