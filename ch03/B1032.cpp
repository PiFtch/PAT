#include <cstdio>

int main() {
    // int school[100001] = {0};
    int n;
    int index, score;
    while (scanf("%d", &n) == 1) {
        int school[100001] = {0};
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &index, &score);
            school[index] += score;
        }
        int maxSchool = 1, maxScore = school[maxSchool];
        for (int i = 1; i <= n; i++) {
            if (school[i] > maxScore) {
                maxSchool = i;
                maxScore = school[i];
            }
        }
        printf("%d %d\n", maxSchool, maxScore);
    }
}