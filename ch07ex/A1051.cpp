/*
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
*/
#include <stack>
#include <iostream>
using namespace std;

int main() {
    int m, n, k;
    stack<int> st;
    // int arr[1010] = {0};
    int poparr[1010] = {0};
    cin >> m >> n >> k;
    // for (int i = 1; i <= n; i++) {
    //     arr[i] = i;
    // }
    for (int i = 1; i <= k; i++) {
        bool flag = true;
        int iarr = 1;   // index waiting for pop
        int in = 1;     // number waiting for push
        for (int i = 1; i <= n; i++) {
            cin >> poparr[i];
        }
        while (iarr <= n) {
            if (poparr[iarr] == in) {
                in++;
                iarr++;
            } else if (poparr[iarr] < in) {
                if (st.top() != in) {
                    flag = false;
                    break;
                } else {
                    st.pop();
                }
            } else {
                while (st.size() < m && st.top() <= poparr[iarr] && in <= n) {
                    st.push(in);
                    in++;
                }
                if (st.top() == poparr[iarr]) {
                    iarr++;
                    st.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;
    }
}