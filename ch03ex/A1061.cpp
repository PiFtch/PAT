/*
1061 Dating（20 分）

Sherlock Holmes received a note with some strange strings: Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm. It took him only a minute to figure out that those strange strings are actually referring to the coded time Thursday 14:04 -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter D, representing the 4th day in a week; the second common character is the 5th capital letter E, representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is s at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.
Input Specification:

Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.
Output Specification:

For each test case, print the decoded time in one line, in the format DAY HH:MM, where DAY is a 3-character abbreviation for the days in a week -- that is, MON for Monday, TUE for Tuesday, WED for Wednesday, THU for Thursday, FRI for Friday, SAT for Saturday, and SUN for Sunday. It is guaranteed that the result is unique for each case.
Sample Input:

3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

Sample Output:

THU 14:04

*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool judge(char c) {
    if (c >= 'A' && c <= 'G')
        return true;
    return false;
}
bool judge3(char c) {
    if (c >= 'A' && c <= 'N' || c >= '0' && c <= '9')
        return true;
    return false;
}
bool judge2(char c) {
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}
int main() {
    char str1[61], str2[61], str3[61], str4[61];
    scanf("%s %s %s %s", str1, str2, str3, str4);
    // int len1 = strlen(str1);
    // int len2 = strlen(str2);
    int len = min(strlen(str1), strlen(str2));
    int day, hour, minute;
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (flag == 0 && judge(str1[i]) && judge(str2[i]) && str1[i] == str2[i]) {
            day = str1[i] - 'A' + 1;
            flag++;
            // printf("DAY DONE\n");
            continue;
        }
        if (flag == 1 && judge3(str1[i]) && judge3(str2[i]) && str1[i] == str2[i]) {
            if (str1[i] >= '0' && str1[i] <= '9')
                hour = str1[i] - '0';
            else
                hour = str1[i] - 'A' + 10;
            flag++;
            // printf("HOUR DOWN: %c %d\n", str1[i], hour);
        }
        if (flag > 1)
            break;
    }
    len = min(strlen(str3), strlen(str4));
    for (int i = 0; i < len; i++) {
        if (judge2(str3[i]) && judge2(str4[i]) && str3[i] == str4[i]) {
            minute = i;
            break;
        }
    }
    switch (day) {
        case 1: printf("MON "); break;
        case 2: printf("TUE "); break;
        case 3: printf("WED "); break;
        case 4: printf("THU "); break;
        case 5: printf("FRI "); break;
        case 6: printf("SAT "); break;
        case 7: printf("SUN "); break;
        default: break;
    }
    printf("%02d:%02d", hour, minute);
}