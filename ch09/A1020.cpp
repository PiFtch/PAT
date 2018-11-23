#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int data;
    node *lchild, *rchild;
};

int n, post[30], in[30];

node* create(int postL, int postR, int inL, int inR) {
    if (postL > postR)
        return NULL;
    node *Node = new node;
    Node->data = post[postR];
    int i;
    for (i = inL; i <= inR; i++) {
        if (in[i] == post[postR])
            break;
    }
    int numLeft = i - inL;

    Node->lchild = create(postL, postL+numLeft-1, inL, i-1);
    Node->rchild = create(postL+numLeft, postR-1, i+1, inR);
    return Node;
}

void levelOrder(node *root) {
    if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    int count = 0;
    while (!q.empty()) {
        node *top = q.front();
        q.pop();
        count++;
        if (count == n)
            printf("%d", top->data);
        else
            printf("%d ", top->data);
        if (top->lchild != NULL)
            q.push(top->lchild);
        if (top->rchild != NULL)
            q.push(top->rchild);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    node *root = create(0, n-1, 0, n-1);
    levelOrder(root);
}