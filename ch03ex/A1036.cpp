/*
1036 Boys vs Girls（25 分）

This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.
Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.
Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference grade​F​​−grade​M​​. If one such kind of student is missing, output Absent in the corresponding line, and output NA in the third line instead.
Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95

Sample Output 1:

Mary EE990830
Joe Math990112
6

Sample Input 2:

1
Jean M AA980920 60

Sample Output 2:

Absent
Jean AA980920
NA

*/
#include <cstdio>
struct student {
    char name[11], id[11];
    char gender;
    int score;
}temp, lowestM, highestF;

int main() {
    lowestM.gender = 'M'; lowestM.score = 101;
    highestF.gender = 'F'; highestF.score = -1;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %c %s %d", &temp.name, &temp.gender, &temp.id, &temp.score);
        if (temp.gender == 'M') {
            if (temp.score < lowestM.score) {
                lowestM = temp;
            }
        } else {
            if (temp.score > highestF.score) {
                highestF = temp;
            }
        }
    }
    bool flag = true;
    if (highestF.score != -1) {
        printf("%s %s\n", highestF.name, highestF.id);
    } else {
        flag = false;
        printf("Absent\n");
    }
    if (lowestM.score != 101) {
        printf("%s %s\n", lowestM.name, lowestM.id);
    } else {
        flag = false;
        printf("Absent\n");
    }
    if (flag)
        printf("%d\n", highestF.score - lowestM.score);
    else {
        printf("NA\n");
    }
}