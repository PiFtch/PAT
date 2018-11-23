/*
1002 A+B for Polynomials（25 分）

This time, you are supposed to find A+B where A and B are two polynomials.
Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N​1​​ a​N​1​​​​ N​2​​ a​N​2​​​​ ... N​K​​ a​N​K​​​​

where K is the number of nonzero terms in the polynomial, N​i​​ and a​N​i​​​​ (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10，0≤N​K​​<⋯<N​2​​<N​1​​≤1000.
Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
Sample Input:

2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output:

3 2 1.5 1 2.9 0 3.2

*/
#include <cstdio>
struct term {
    double exp, coe;
}a[20], b[20], sum[30];



int main() {
    int k1, k2;
    scanf("%d", &k1);
    for (int i = 0; i < k1; i++) {
        scanf("%lf %lf", &a[i].exp, &a[i].coe);
    }
    scanf("%d", &k2);
    for (int i = 0; i < k2; i++){
        scanf("%lf %lf", &b[i].exp, &b[i].coe);
    }
    int p1 = 0, p2 = 0, psum = 0;
    
    for (p1 = 0; p1 < k1; p1++) {
        while (p2 < k2 && a[p1].exp < b[p2].exp) {
            sum[psum].exp = b[p2].exp;
            sum[psum++].coe = b[p2].coe;
            p2++;
        }
        if (p2 < k2 && a[p1].exp == b[p2].exp) {
            double coesum = a[p1].coe + b[p2].coe;
            if (coesum != 0) {
                sum[psum].exp = a[p1].exp;
                sum[psum++].coe = coesum;
            }
            p2++;
        } else {
            sum[psum].exp = a[p1].exp;
            sum[psum++].coe = a[p1].coe;
        }
    }
    

    printf("%d ", psum);
    for (int i = 0; i < psum; i++) {
        printf("%.0lf %.1lf", sum[i].exp, sum[i].coe);
        if (i < psum - 1)
            printf(" ");
    }
}