#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int weight;
    vector<int> child;
} nodes[100];

bool cmp(int a, int b) {
    return nodes[a].weight > nodes[b].weight;
}
int n, m, s;
vector<int> temp, ans;

void DFS(int index, int sum) {
    sum += nodes[index].weight;
    temp.push_back(nodes[index].weight);
    if (sum > s) {
        temp.pop_back();
        return;
    }
    if (sum == s) {
        if (nodes[index].child.size() != 0) {
            temp.pop_back();
            return;
        }
        for (int i = 0; i < temp.size(); i++) {
            printf("%d", temp[i]);
            if (i < temp.size() - 1)
                printf(" ");
            else
                printf("\n");
        }
        temp.pop_back();
        return;
    }
    for (int i = 0; i < nodes[index].child.size(); i++) {
        int child = nodes[index].child[i];
        DFS(child, sum);
    }
    temp.pop_back();
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &nodes[i].weight);
    int index, k, temp;
    for (int i = 0; i < m; i++) {
        scanf("%2d %d", &index, &k);
        for (int j = 0; j < k; j++) {
            scanf("%2d", &temp);
            nodes[index].child.push_back(temp);
        }
        sort(nodes[index].child.begin(), nodes[index].child.end(), cmp);
    }

    DFS(0, 0);
}