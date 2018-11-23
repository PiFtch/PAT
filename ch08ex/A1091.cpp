#include <cstdio>
#include <queue>
using namespace std;

const int maxm = 1286;
const int maxn = 128;
const int maxl = 60;

struct node {
    int x, y, z;
} Node;
int matrix[maxl][maxm][maxn];
bool inq[maxl][maxm][maxn] = {false};
int X[6] = {-1, 0, 0, 0, 0, 1};
int Y[6] = {0, 1, -1, 0, 0, 0};
int Z[6] = {0, 0, 0, 1, -1, 0};
int m, n, l, t;

bool test(int slice, int row, int col) {
    if (slice >= l || slice < 0 || row >= m || row < 0 || col >= n || col < 0)
        return false;
    if (inq[slice][row][col] || matrix[slice][row][col] == 0)
        return false;
    return true;
}
int BFS(int slice, int row, int col) {
    int count = 0;
    queue<node> q;
    Node.x = slice;
    Node.y = row;
    Node.z = col;
    q.push(Node);
    inq[slice][row][col] = true;
    while (!q.empty()) {
        node top = q.front();
        q.pop();
        count++;
        for (int i = 0; i < 6; i++) {
            int newSlice = slice + Z[i], newRow = row + Y[i], newCol = col + X[i];
            if (test(newSlice, newRow, newCol)) {
                Node.x = newSlice;
                Node.y = newRow;
                Node.z = newCol;
                q.push(Node);
                inq[newSlice][newRow][newCol] = true;
                // count++;
            }
        }
    }
    if (count >= t)
        return count;
    else
        return 0;
}

int main() {
    scanf("%d%d%d%d", &m, &n, &l, &t);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &matrix[i][j][k]);
                inq[i][j][k] = false;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (matrix[i][j][k] == 1 && inq[i][j][k] == false) {
                    sum += BFS(i, j, k);
                }
            }
        }
    }
    printf("%d\n", sum);
}