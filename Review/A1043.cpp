#include <cstdio>
#include <vector>
using namespace std;
struct node {
	int data;
	node *left, *right;
};

int n;
node *root = NULL;
vector<int> origin;

void insert(node *&root, int data) {
	if (root == NULL) {
		printf("INSERT %d\n", data);
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	
	if (data < root->data) {
		insert(root->left, data);
	} else {
		insert(root->right, data);
	}
}

void pre(node *root) {
	if (root == NULL)
		return;
		
	printf("%d ", root->data);
	pre(root->left);
	pre(root->right);
}
int main() {
	scanf("%d", &n);
	int temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		origin.push_back(temp);
		insert(root, temp);
	}
	printf("MARK1\n");
	pre(root);
}

