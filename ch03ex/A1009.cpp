/*
1009 Product of Polynomials（25 分）

This time, you are supposed to find A×B where A and B are two polynomials.
Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N​1​​ a​N​1​​​​ N​2​​ a​N​2​​​​ ... N​K​​ a​N​K​​​​

where K is the number of nonzero terms in the polynomial, N​i​​ and a​N​i​​​​ (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10, 0≤N​K​​<⋯<N​2​​<N​1​​≤1000.
Output Specification:

For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
Sample Input:

2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output:

3 3 3.6 2 6.0 1 1.6

*/
#include <cstdio>
double a[1001], b[1001], c[2005];


int main() {
    int k1, k2, exp;
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++) {
        scanf("%d", &exp);
        scanf("%lf", &a[exp]);
    }
    scanf("%d", &k2);
    for (int i = 0; i < k2; i++) {
        scanf("%d", &exp);
        scanf("%lf", &b[exp]);
        int exp2;
        for (int j = 0; j < 1001; j++) {
            if (a[j] != 0) {
                exp2 = j + exp;
                c[exp2] += a[j] * b[exp];
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 2002; i++) {
        if (c[i] != 0)
            count++;
    }
    printf("%d", count);
    for (int i = 2002; i >= 0; i--) {
        if (c[i] != 0)
            printf(" %d %.1lf", i, c[i]);
    }
}