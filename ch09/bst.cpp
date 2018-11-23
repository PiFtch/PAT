#include <cstdio>

struct node {
    int data;
    node *lchild, *rchild;
};

void search(node *root, int x) {
    if (root == NULL) {
        printf("search failed.\n");
        return;
    }
    if (root->data == x)
        printf("%d\n", root->data);
    else if (x < root->data) 
        search(root->lchild, x);
    else
        search(root->rchild, x);
}

void insert(node* &root, int x) {
    // if (root == NULL) {
    //     root = new node;
    //     root->data = x;
    //     return;
    // }
    if (root == NULL) {
        root = new node;
        root->data = x;
        return;
    }
    if (root->data == x)
        return;
    else if (x < root->data)
        if (root->lchild != NULL)
            insert(root->lchild, x);
        else {
            root->lchild = new node;
            root->lchild->data = x;
            root->lchild->lchild = root->lchild->rchild = NULL;
        }
    else
        if (root->rchild != NULL)
            insert(root->rchild, x);
        else {
            root->rchild = new node;
            root->rchild->data = x;
            root->rchild->lchild = root->rchild->rchild = NULL;
        }
}

node *create(int data[], int n) {
    node *root = new node;
    for (int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

void preOrder(node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

int main() {
    int arr[7] = {5,3,7,4,2,8,6};
    node *root = create(arr, 7);
    if (root == NULL)
        printf("YES\n");
    else
        printf("NO\n");
    preOrder(root);
    return 0;
}