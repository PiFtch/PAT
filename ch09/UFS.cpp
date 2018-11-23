#include <cstdio>

int father[100];
int findFather(int x) {
    while (x != father[x]) {
        x = father[x];
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
        father[faA] = faB;
}
int main() {

}