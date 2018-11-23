/*
1013 数素数（20 分）

令 P?i?? 表示第 i 个素数。现任给两个正整数 M≤N≤10?4??，请输出 P?M?? 到 P?N?? 的所有素数。
输入格式：

输入在一行中给出 M 和 N，其间以空格分隔。
输出格式：

输出从 P?M?? 到 P?N?? 的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。
输入样例：

5 27

输出样例：

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

*/
#include <cstdio>
#include <cmath>
int prime[10001];

bool isPrime(int n) {
	if (n <= 1)
		return false;
	else {
		int sqr = (int)sqrt(n * 1.0);
		for (int i = 2; i <= sqr; i++) {
			if (n % i == 0)
				return false;
		}
	}
	return true;
}

int main() {
	int pNum = 1;
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 1; pNum <= n; i++) {
		if (isPrime(i)) {
			prime[pNum++] = i;
		}
	}
	int count = 0;
	for (int i = m; i <= n; i++) {
		if (i < n) {
			if (count < 9) {
				count++;
				printf("%d ", prime[i]);
			} else {
				printf("%d\n", prime[i]);
				count = 0;
			}
		} else {
			printf("%d", prime[i]);
		}
	}
}
