/*
1006 Sign In and Sign Out（25 分）

At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.
Input Specification:

Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time

where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.
Output Specification:

For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.
Sample Input:

3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

Sample Output:

SC3021234 CS301133

*/
#include <cstdio>
struct person {
    char id[16];
    int hour, minute, second;
    int hour2, minute2, second2;
}temp, unlock, lock;

person isUnlock(person a, person b) {
    if (a.hour < b.hour) {
        return a;
    } else if (a.hour > b.hour) {
        return b;
    } else {
        if (a.minute < b.minute)
            return a;
        else if (a.minute > b.minute)
            return b;
        else {
            if (a.second < b.second)
                return a;
            else if (a.second > b.second)
                return b;
            else {
                return b;
            }
        }
    }
}
person isLock(person a, person b) {
    if (a.hour2 > b.hour2) 
        return a;
    else if (a.hour2 < b.hour2)
        return b;
    else {
        if (a.minute2 > b.minute2)
            return a;
        else if (a.minute2 < b.minute2)
            return b;
        else {
            if (a.second2 > b.second2)
                return a;
            else
                return b;
        }
    }
}
int main() {
    unlock.hour = 24; unlock.minute = 60; unlock.second = 60;
    lock.hour2 = 0; lock.minute2 = 0; lock.second2 = 0;
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s %2d:%2d:%2d %2d:%2d:%2d", &temp.id, &temp.hour, &temp.minute, &temp.second, &temp.hour2, &temp.minute2, &temp.second2);
        unlock = isUnlock(temp, unlock);
        lock = isLock(temp, lock);
    }
    printf("%s %s", unlock.id, lock.id);
}