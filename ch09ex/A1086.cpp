#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

struct node {
    int data;
    node *lchild, *rchild;
};
int n;
/*
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
*/
int prtnum = 0;
void postOrder(node *root) {
    if (root == NULL)
        return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    prtnum++;
    if (prtnum == n)
        printf("%d", root->data);
    else
        printf("%d ", root->data);
}

int main() {
    scanf("%d", &n);
    char str[10];
    stack<node*> st;
    node *top, *root;
    bool flag = true;
    for (int i = 0; i < 2*n; i++) {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0) { 
            node *Node = new node;
            scanf("%d", &Node->data);
            Node->lchild = Node->rchild = NULL;
            if (flag) {
                if (!st.empty()) {
                    top = st.top();
                    top->lchild = Node;
                }
            } else {
                top->rchild = Node;
            }
            st.push(Node);
            flag = true;
            if (i == 0)
                root = Node;
        } else {
            flag = false;
            top = st.top();
            st.pop();
        }
    }

    postOrder(root);
}