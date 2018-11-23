#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;
struct Interval {
    int x, y;
} intervals[maxn];

bool cmp (Interval a, Interval b) {
    if (a.x != b.x)
        return a.x > b.x;
    else
        return a.y < b.y;
}

int main() {
    int n;
    while (scanf("%d", &n), n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &intervals[i].x, &intervals[i].y);
        }
        sort(intervals, intervals+n, cmp);
        int ans = 1, lastX = intervals[0].x;
        for (int i = 1; i < n; i++) {
            if (intervals[i].y <= lastX) {
                lastX = intervals[i].x;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}