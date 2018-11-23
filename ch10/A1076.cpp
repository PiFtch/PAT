#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> graph[1001];
bool vis[1001];
int level[1001];
int countForward = 0;
int n, l;
void BFS(int id) {
    level[id] = 0;
    countForward = -1;
    queue<int> q;
    vis[id] = true;
    q.push(id);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        countForward++;
        for (int i = 0; i < graph[front].size(); i++) {
            int follower = graph[front][i];
            if (level[front] == l)
                break;
            if (!vis[follower]) {
                q.push(follower);
                vis[follower] = true;
                level[follower] = level[front] + 1;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &l);
    int m, user;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &user);
            graph[user].push_back(i);
        }
    }
    int k, userID;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &userID);
        memset(vis, false, n+1);
        BFS(userID);
        printf("%d\n", countForward);
    }
}