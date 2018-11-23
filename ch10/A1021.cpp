#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100010;
vector<int> g[N];

bool isRoot[N];
int father[N];
int findFather(int x) {
    int temp1 = x;
    while (x != father[x])
        x = father[x];
    while (temp1 != father[temp1]) {
        int temp2 = temp1;
        temp1 = father[temp1];
        father[temp2] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faA] = faB;
    }
}
void init(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int calBlock(int n) {
    int block = 0;
    for (int i = 1; i <= n; i++) {
        isRoot[findFather(i)] = true;
    }
    for (int i = 1; i <= n; i++) {
        block += isRoot[i];
    }
    return block;
}

int maxH = 0;
vector<int> temp, ans;

void DFS(int u, int height, int pre) {
    if (height > maxH) {
        temp.clear();
        temp.push_back(u);
        maxH = height;
    } else if (height == maxH) {
        temp.push_back(u);
    }
    for (int i = 0; i < g[u].size(); i++) {
        if (g[u][i] == pre)
            continue;
        DFS(g[u][i], height+1, u);
    }
}

int main() {
    int n, id1, id2;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &id1, &id2);
        g[id1].push_back(id2);
        g[id2].push_back(id1);
        Union(id1, id2);
    }
    int block = calBlock(n);
    if (block != 1) {
        printf("Error: %d components\n", block);
    } else {
        DFS(1, 1, -1);
        ans = temp;
        DFS(ans[0], 1, -1);
        for (int i = 0; i < temp.size(); i++) {
            ans.push_back(temp[i]);
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans[0]);
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] != ans[i-1]) {
                printf("%d\n", ans[i]);
            }
        }
    }
}