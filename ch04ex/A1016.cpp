#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct record {
    char name[21];
    int month, day, hour, minute;
    bool online;
} records[1001], temp;
struct customer {
    char name[21];
    vector<record> records;
};
vector<customer> customers;
int charge[24];
bool cmp(record a, record b) {
    int diff = strcmp(a.name, b.name);
    if (diff != 0) {
        return diff < 0;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    if (a.day != b.day)
        return a.day < b.day;
    if (a.hour != b.hour)
        return a.hour < b.hour;
    return a.minute < b.minute;
}
void calc(int on, int off, int &time, int &total) {
    temp = records[on];
    while (temp.day < records[off].day || temp.hour < records[off].hour || temp.minute < records[off].minute) {
        temp.minute++;
        time++;
        total += charge[temp.hour];
        if (temp.minute >= 60) {
            temp.minute = 0;
            temp.hour++;
        }
        if (temp.hour >= 24) {
            temp.hour = 0;
            temp.day++;
        }
    }
    
}
int main() {
    for (int i = 0; i < 24; i++) {
        scanf("%d", &charge[i]);
    }
    int n; char str[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %2d:%2d:%2d:%2d %s", records[i].name, &records[i].month, &records[i].day, &records[i].hour, &records[i].minute, str);
        if (strcmp(str, "on-line") == 0) {
            records[i].online = true;
        } else {
            records[i].online = false;
        }
    }
    sort(records, records+n, cmp);

    char name[21];
    int pair = 0;
    int on = 0, next;
    int off;
    while (on < n) {
        pair = 0;
        next = on;
        
        while (next < n && strcmp(records[next].name, records[on].name) == 0) {
            if (pair == 0 && records[next].online) {
                pair = 1;
            } else if (pair == 1 && records[next].online == false) {
                pair = 2;
            }
            next++;
        }
        if (pair < 2) {
            on = next;
            continue;
        }
        int total = 0;
        printf("%s %02d\n", records[on].name, records[on].month);
        while (on < next) {
            while (on < next - 1 && !(records[on].online && !records[on+1].online))
                on++;
            off = on + 1;
            if (off == next) {
                on = next;
                break;
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d ", records[on].day, records[on].hour, records[on].minute, records[off].day, records[off].hour, records[off].minute);
            int time = 0, money = 0;
            calc(on, off, time, money);
            total += money;
            printf("%d $%.2f\n", time, money/100.0);
            on = off + 1;
        }
        printf("Total amount: $%.2f\n", total/100.0);
    }
}