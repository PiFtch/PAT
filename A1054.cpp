#include <cstdio>
/*
int image[600][800];
int hashTable[16777216];
int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &image[i][j]);
      hashTable[image[i][j]]++;
    }
  }
  int max = 0, color = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (hashTable[image[i][j]] > max) {
        max = hashTable[image[i][j];
        color = image[i][j];
      }
    }
  }
  printf("%d\n", color);
}
*/
int main() {
    int m, n, temp, freq = 0, ans;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &temp);
            if (freq == 0) {
                ans = temp;
                freq = 1;
            } else {
                if (ans == temp) {
                    freq++;
                } else {
                    
                }
            }
        }
    }
}