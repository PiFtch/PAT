#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int begin = 0, end = str.length()-1;
        bool flag = true;
        while (begin <= end) {
            if (str[begin] == str[end]) {
                begin++;
                end--;
            } else {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}