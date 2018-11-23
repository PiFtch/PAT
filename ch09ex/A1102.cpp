#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;
struct node {
    int data;
    int lchild, rchild;
} nodes[10];
int n;
bool hashTable[10] = {false};

void levelOrder(int root) {
    if (root == -1)
        return;
    queue<int> q;
    q.push(root);
    int count = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        count++;
        if (count != n)
            printf("%d ", top);
        else
            printf("%d\n", top);
        
        if (nodes[top].lchild != -1)
            q.push(nodes[top].lchild);
        if (nodes[top].rchild != -1)
            q.push(nodes[top].rchild);
    }
}
int inorderCount = 0;
void inOrder(int root) {
    if (root == -1)
        return;
    inOrder(nodes[root].lchild);
    inorderCount++;
    if (inorderCount == n)
        printf("%d", root);
    else
        printf("%d ", root);
    inOrder(nodes[root].rchild);
    
}
int main() {
    scanf("%d", &n);
    // char left[2], right[2];
    char left, right;
    for (int i = 0; i < n; i++) {
        // scanf("%s", left);
        // scanf("%s", right);
        scanf("%*c%c %c", &left, &right);
        nodes[i].data = i;
        if (left != '-') {
            nodes[i].rchild = left - '0';
            hashTable[left - '0'] = true;
        }
        else
            nodes[i].rchild = -1;
        if (right != '-') {
            nodes[i].lchild = right - '0';
            hashTable[right - '0'] = true;
        }
        else
            nodes[i].lchild = -1;
        
    }
    // printf("%s%s", left, right);
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (!hashTable[i]) {
            root = i;
            break;
        }
    }

    levelOrder(root);
    inOrder(root);
}