#include <cstdio>

int dis[100010];
int clockwise[10010];


int main() {
    int n, m, sum = 0;
    int exit1, exit2;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dis[i]);
        sum += dis[i];
        clockwise[i] = sum;
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &exit1, &exit2);
        int path1 = 0, path2 = 0;
        if (exit1 < exit2) {
            path1 = clockwise[exit2 - 1] - clockwise[exit1 - 1];
            path2 = sum - path1;
            /*
            for (int j = exit1; j < exit2; j++) {
                path1 += dis[j];
            }
            */
            /*
            for (int j = exit2; j <= n; j++) {
                path2 += dis[j];
            }
            for (int j = 1; j < exit1; j++) {
                path2 += dis[j];
            }
            */
        } else {
            path1 = clockwise[exit1 - 1] - clockwise[exit2 - 1];
            path2 = sum - path1;
            /*
            for (int j = exit2; j < exit1; j++) {
                path1 += dis[j];
            }
            */
            /*
            for (int j = exit1; j <= n; j++) {
                path2 += dis[j];
            }
            for (int j = 1; j < exit2; j++) {
                path2 += dis[j];
            }
            */
        }
        if (path1 < path2) {
            printf("%d\n", path1);
        } else {
            printf("%d\n", path2);
        }
    }
}