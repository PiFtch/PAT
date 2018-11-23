#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct pos {
	int slice, row, col;
	pos(int s, int r, int c) {
		slice = s;
		row = r;
		col = c;
	}
};

const int maxL = 60;
const int maxM = 1286;
const int maxN = 128;
int matrix[maxL][maxM][maxN];
bool vis[maxL][maxM][maxN] = {false};
int m, n, l, t;
int totalCores = 0;

bool judge(int slice, int row, int col) {
	if (slice >= l || slice < 0 || row >= m || row < 0 || col >= n || col < 0) {
		return false;
	}
	if (matrix[slice][row][col] == 0 || vis[slice][row][col])
		return false;
	return true;
}

int findVol(int slice, int row, int col) {
	int count = 0;
	queue<pos> q;
	pos node(slice, row, col);
	q.push(node);
	vis[slice][row][col] = true;
	while (!q.empty()) {
		pos top = q.front();
		q.pop();
		count++;
		int newSlice, newRow, newCol;
		//
		newSlice = top.slice; newRow = top.row; newCol = top.col - 1;
		if (judge(newSlice, newRow, newCol)) {
			node.slice = newSlice; node.row = newRow; node.col = newCol;
			q.push(node);
			vis[newSlice][newRow][newCol] = true;
		}
		
		newSlice = top.slice; newRow = top.row; newCol = top.col + 1;
		if (judge(newSlice, newRow, newCol)) {
			node.slice = newSlice; node.row = newRow; node.col = newCol;
			q.push(node);
			vis[newSlice][newRow][newCol] = true;
		}
		
		newSlice = top.slice; newRow = top.row - 1; newCol = top.col;
		if (judge(newSlice, newRow, newCol)) {
			node.slice = newSlice; node.row = newRow; node.col = newCol;
			q.push(node);
			vis[newSlice][newRow][newCol] = true;
		}
		
		newSlice = top.slice; newRow = top.row + 1; newCol = top.col;
		if (judge(newSlice, newRow, newCol)) {
			node.slice = newSlice; node.row = newRow; node.col = newCol;
			q.push(node);
			vis[newSlice][newRow][newCol] = true;
		}
		
		newSlice = top.slice - 1; newRow = top.row; newCol = top.col;
		if (judge(newSlice, newRow, newCol)) {
			node.slice = newSlice; node.row = newRow; node.col = newCol;
			q.push(node);
			vis[newSlice][newRow][newCol] = true;
		}
		
		newSlice = top.slice + 1; newRow = top.row; newCol = top.col;
		if (judge(newSlice, newRow, newCol)) {
			node.slice = newSlice; node.row = newRow; node.col = newCol;
			q.push(node);
			vis[newSlice][newRow][newCol] = true;
		}
	}
	if (count >= t) return count;
	else return 0;
}

int main() {
	scanf("%d %d %d %d", &m, &n, &l, &t);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%d", &matrix[i][j][k]);
			}
		}
	}
	
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (!vis[i][j][k] && matrix[i][j][k] == 1) {
					totalCores += findVol(i, j, k);
				}
			}
		}
	}
	printf("%d\n", totalCores);
}
