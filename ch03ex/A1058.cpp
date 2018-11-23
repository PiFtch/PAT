/*
1058 A+B in Hogwarts（20 分）

If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of Galleon.Sickle.Knut (Galleon is an integer in [0,10​7​​], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).
Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.
Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input.
Sample Input:

3.2.1 10.16.27

Sample Output:

14.1.28

*/
#include <cstdio>
int a[3], b[3], c[3];
void proc(int *num) {
    // int c = 0;
    num[1] += num[2] / 29;
    num[2] = num[2] % 29;
    num[0] += num[1] / 17;
    num[1] = num[1] % 17;
}
int main() {
    scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
    scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
    for (int i = 0; i < 3; i++) {
        c[i] = a[i] + b[i];
    }
    proc(c);
    for (int i = 0; i < 3; i++) {
        printf("%d", c[i]);
        if (i != 2)
            printf(".");
    }
}
