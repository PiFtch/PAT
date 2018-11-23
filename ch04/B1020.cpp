#include <cstdio>
#include <algorithm>

struct mooncake {
    double store;   // 库存
    double price;   // 单价
    double sell;    // 总售价
} mooncakes[1010];

bool cmp(mooncake a, mooncake b) {
    return a.price > b.price;
}
int main() {
    int n; double need;
    double res = 0.0;
    scanf("%d %lf", &n, &need);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &mooncakes[i].store);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &mooncakes[i].sell);
        mooncakes[i].price = mooncakes[i].sell / mooncakes[i].store;
    }
    std::sort(mooncakes, mooncakes+n, cmp);
    for (int i = 0; i < n && need > 0; i++) {
        if (need >= mooncakes[i].store) {
            res += mooncakes[i].sell;
            need -= mooncakes[i].store;
        } else {
            res += need * mooncakes[i].price;
            need = 0;
        }
    }
    printf("%.2lf\n", res);
    return 0;
}