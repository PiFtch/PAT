#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;

struct node {
    int data;
    node *lchild;
    node *rchild;
    int layer;
};

node* newNode(int v) {
    node *Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int pre[maxn];
int in[maxn];

node *create(int preL, int preR, int inL, int inR) {
    if (preL > preR)
        return NULL;
    node *root = new node;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == pre[preL])
            break;
    }
    int numLeft = k - inL;

    root->lchild = create(preL+1, preL+numLeft, inL, k-1);
    root->rchild = create(preL+numLeft+1, preR, k+1, inR);

    return root;
}

void preOrder(node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void inOrder(node *root) {
    if (root == NULL)
        return;
    inOrder(root->lchild);
    printf("%d ", root->data);
    inOrder(root->rchild);
}

void postOrder(node *root) {
    if (root == NULL)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d ", root->data);
}

void levelOrder(node *root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node *top = q.front();
        q.pop();
        printf("%d ", top->data);
        if (top->lchild != NULL)
            q.push(top->lchild);
        if (top->rchild != NULL)
            q.push(top->rchild);
    }
}

int main() {
    // pre[] = {4,1,3,2,6,5,7};
    // in[] = {1};
    for (int i = 0; i < 7; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < 7; i++)
        scanf("%d", &in[i]);
    node *root = create(0, 6, 0, 6);
    preOrder(root);
    inOrder(root);
    postOrder(root);
    levelOrder(root);
}