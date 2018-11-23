/*
1027 Colors in Mars（20 分）

People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.
Input Specification:

Each input file contains one test case which occupies a line containing the three decimal color values.
Output Specification:

For each test case you should output the Mars RGB value in the following format: first output #, then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a 0 to its left.
Sample Input:

15 43 71

Sample Output:

#123456

*/
#include <cstdio>
#include <map>
using namespace std;
const int radix = 13;
map<int, char> mp;

int color[6];
void change(int color, int *arr) {
    int i = 1;
    while (color > 0) {
        arr[i--] = color % radix;
        color /= radix;
    }
}
int main() {
    mp[10] = 'A'; mp[11] = 'B'; mp[12] = 'C';
    int red, green, blue;
    scanf("%d %d %d", &red, &green, &blue);
    change(red, color);
    change(green, color+2);
    change(blue, color+4);
    printf("#");
    for (int i = 0; i < 6; i++) {
        if (color[i] < 10)
            printf("%d", color[i]);
        else
            printf("%c", mp[color[i]]);
    }
}