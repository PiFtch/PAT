#include <cstdio>
#include <algorithm>
using namespace std;
struct mc {
  double store, price;
  double unit;
}mcs[1001];
bool cmp(mc a, mc b) {
  return a.unit > b.unit;
}
int n, d;
int main() {
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &mcs[i].store);
  }
  for (int i = 0; i < n; i++) {
    scanf("%lf", &mcs[i].price);
    mcs[i].unit = mcs[i].price / mcs[i].store;
  }
  sort(mcs, mcs+n, cmp);
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    if (mcs[i].store <= d) {
      d -= mcs[i].store;
      sum += mcs[i].price;
    //   printf("demand remains %d; sum = %.2lf\n", d, sum);
    } else {
      sum += mcs[i].unit * (double)d;
      break;
    }
  }
  printf("%.2lf", sum);
}