#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct stu {
    char id[7];
    int c, m, e, a;
};
vector<stu> sortC, sortM, sortE, sortA;
bool cmpC(stu a, stu b) {
    return a.c > b.c;
}
bool cmpM(stu a, stu b) {
    return a.m > b.m;
}
bool cmpE(stu a, stu b) {
    return a.e > b.e;
}
bool cmpA(stu a, stu b) {
    return a.a > b.a;
}
int main() {
    int n, m;
    stu temp;
    scanf("%d %d", &n, &m);
    if (m == 0 || n == 0) {
        printf("N/A\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", temp.id, &temp.c, &temp.m, &temp.e);
        temp.a = (temp.c + temp.m + temp.e) / 3;
        sortC.push_back(temp);
    }
    sortM = sortE = sortA = sortC;
    sort(sortC.begin(), sortC.end(), cmpC);
    sort(sortM.begin(), sortM.end(), cmpM);
    sort(sortE.begin(), sortE.end(), cmpE);
    sort(sortA.begin(), sortA.end(), cmpA);
    /*
    for (vector<stu>::iterator it = sortC.begin(); it != sortC.end(); it++) {
        printf("%s %d\n", (*it).id, (*it).c);
    }
    */
    char target[7];
    for (int i = 0; i < m; i++) {
        scanf("%s", target);
        char flag = 'N'; int bestRank = 10000000;
        int preRank = 0, rank = 0;
        for (int i = 0; i < sortA.size(); i++) {
            if (i > 0) {
                if (sortA[i].a == sortA[i-1].a) {
                    rank = preRank;
                } else {
                    rank = preRank = i;
                    // printf("now rank %d prerank %d\n", rank, preRank);
                }
            }
            if (strcmp(target, sortA[i].id) == 0) {
                if (rank < bestRank) {
                    bestRank = rank;
                    flag = 'A';
                }
                break;
            }
        }
        preRank = rank = 0;
        for (int i = 0; i < sortC.size(); i++) {
            if (i > 0) {
                if (sortC[i].c == sortC[i-1].c) {
                    rank = preRank;
                } else {
                    rank = preRank = i;
                }
            }
            if (strcmp(target, sortC[i].id) == 0) {
                if (rank < bestRank) {
                    bestRank = rank;
                    flag = 'C';
                }
                break;
            }
        }
        preRank = rank = 0;
        for (int i = 0; i < sortM.size(); i++) {
            if (i > 0) {
                if (sortM[i].m == sortM[i-1].m) {
                    rank = preRank;
                } else {
                    rank = preRank = i;
                }
            }
            if (strcmp(target, sortM[i].id) == 0) {
                if (rank < bestRank) {
                    bestRank = rank;
                    flag = 'M';
                }
                break;
            }
        }
        preRank = rank = 0;
        for (int i = 0; i < sortE.size(); i++) {
            if (i > 0) {
                if (sortE[i].e == sortE[i-1].e) {
                    rank = preRank;
                } else {
                    rank = preRank = i;
                }
            }
            if (strcmp(target, sortE[i].id) == 0) {
                if (rank < bestRank) {
                    bestRank = rank;
                    flag = 'E';
                }
                break;
            }
        }
        if (bestRank != 10000000)
            printf("%d %c\n", bestRank+1, flag);
        else
            printf("N/A\n");
    }
}