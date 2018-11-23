#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct stu {
    int id;
    char name[9];
    int grade;
} students[100005];
bool cmp1(stu a, stu b) {
    return a.id < b.id;
}
bool cmp2(stu a, stu b) {
    int diff = strcmp(a.name, b.name);
    if (diff != 0)
        return diff < 0;
    else
        return a.id < b.id;
}
bool cmp3(stu a, stu b) {
    if (a.grade != b.grade)
        return a.grade < b.grade;
    else
        return a.id < b.id;
}
int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%6d %s %d", &students[i].id, students[i].name, &students[i].grade);
    }
    switch (c) {
        case 1: sort(students, students+n, cmp1); break;
        case 2: sort(students, students+n, cmp2); break;
        case 3: sort(students, students+n, cmp3); break;
    }
    for (int i = 0; i < n; i++) {
        printf("%06d %s %d\n", students[i].id, students[i].name, students[i].grade);
    }
}