/*
1013 ��������20 �֣�

�� P?i?? ��ʾ�� i �����������θ����������� M��N��10?4??������� P?M?? �� P?N?? ������������
�����ʽ��

������һ���и��� M �� N������Կո�ָ���
�����ʽ��

����� P?M?? �� P?N?? ������������ÿ 10 ������ռ 1 �У�����Կո�ָ�������ĩ�����ж���ո�
����������

5 27

���������

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
