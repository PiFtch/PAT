/*
1085 Perfect Sequence (25)（25 分）

Given a sequence of positive integers and another positive integer p. The sequence is said to be a "perfect sequence" if M <= m * p where M and m are the maximum and minimum numbers in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (<= 10^5^) is the number of integers in the sequence, and p (<= 10^9^) is the parameter. In the second line there are N positive integers, each is no greater than 10^9^.

Output Specification:

For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:

10 8
2 3 20 4 5 1 6 7 8 9

Sample Output:

8
*/
#include <cstdio>
#include <algorithm>
using namespace std;

long long num[100010];

int main() {
    int n; long long p;
    scanf("%d%lld", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
    }
    sort(num, num+n);       // low to high
    int maxLength = 0;
    int length;
    long long max, min;
    for (int index = n-1; index >= 0; index--) {
        max = num[index];
        int left = 0, right = index;
        while (left < right) {
            int mid = (left + right) / 2;
            if (num[mid] * p >= max) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (num[left] * p >= max) {
            length = index - left + 1;
        } else {
            length = 0;
        }
        if (length > maxLength)
            maxLength = length;
    }
    printf("%d\n", maxLength);
}