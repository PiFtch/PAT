#include <cstdio>
#include <algorithm>
using namespace std;

int inList[1010];
int n;
int cbt[1010];

int index = 0;
void inOrder(int root) {
	if (root > n)
		return;
		
	inOrder(root * 2);
	cbt[root] = inList[index++];
	inOrder(root * 2 + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &inList[i]);
	}
	sort(inList, inList + n);
	
	inOrder(1);
	for (int i = 1; i <= n; i++)
		printf("%d ", cbt[i]);
}
