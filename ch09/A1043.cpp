#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int data;
    node *left, *right;
};
int n, temp;
vector<int> origin, pre, preM, post, postM;
void insert(node* &root, int data) {
    if (root == NULL) {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if (data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

void preOrder(node *root) {
    if (root == NULL)
        return;
    pre.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void preOrderM(node *root) {
    if (root == NULL)
        return;
    preM.push_back(root->data);
    preOrderM(root->right);
    preOrderM(root->left);
}

void postOrder(node *root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->data);
}

void postOrderM(node *root) {
    if (root == NULL)
        return;
    postOrderM(root->right);
    postOrderM(root->left);
    postM.push_back(root->data);
}
int main() {
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        origin.push_back(temp);
        insert(root, temp);
    }
    preOrder(root);
    preOrderM(root);
    if (origin == pre) {
        printf("YES\n");
        postOrder(root);
        int size = post.size();
        for (int i = 0; i < size; i++)
            if (i < size - 1)
                printf("%d ", post[i]);
            else
                printf("%d\n", post[i]);
    } else if (origin == preM) {
        printf("YES\n");
        postOrderM(root);
        int size = postM.size();
        for (int i = 0; i < size; i++)
            if (i < size-1)
                printf("%d ", postM[i]);
            else
                printf("%d\n", postM[i]);
    } else
        printf("NO\n");
}