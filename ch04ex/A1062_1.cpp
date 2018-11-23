#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Person {
    char id[10];
    int virtue;
    int talent;
    int flag; // 1-5
} persons[100010];

bool cmp(Person a, Person b) {
    if (a.flag != b.flag)
        return a.flag < b.flag;
    else {
        int suma = a.virtue+a.talent, sumb = b.virtue+b.talent;
        if (suma != sumb)
            return suma > sumb;
        else if (a.virtue != b.virtue)
            return a.virtue > b.virtue;
        else
            return strcmp(a.id, b.id) < 0;
    }
}

int main() {
    int n, low, high;
    int num = 0;
    scanf("%d %d %d", &n, &low, &high);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", persons[i].id, &persons[i].virtue, &persons[i].talent);
        if (persons[i].virtue >= low && persons[i].talent >= low) {
            if (persons[i].virtue >= high && persons[i].talent >= high)
                persons[i].flag = 1;
            else if (persons[i].virtue >= high)
                persons[i].flag = 2;
            else if (persons[i].virtue >= persons[i].talent)
                persons[i].flag = 3;
            else
                persons[i].flag = 4;
            num++;
        } else
            persons[i].flag = 5;
    }
    sort(persons, persons+n, cmp);
    printf("%d\n", num);
    for (int i = 0; i < num; i++) {
        printf("%s %d %d\n", persons[i].id, persons[i].virtue, persons[i].talent);
    }
}