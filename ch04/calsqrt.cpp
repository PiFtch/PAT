#include <iostream>
using namespace std;

const double eps = 1e-5;

double f(double x) {
    return x * x;
}

double calsqrt() {
    double left = 1, right = 2, mid;
    while (right - left > eps) {
        mid = (right + left) / 2;
        if (f(mid) < 2) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return mid;
}

int main() {
    cout << calsqrt() << endl;
}