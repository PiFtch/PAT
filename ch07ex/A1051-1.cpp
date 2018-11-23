#include <iostream>
#include <stack>
using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    stack<int> st;
    int popSequence[1010] = {0};
    for (int i = 0; i < K; i++) {
        for (int j = 1; j <= N; j++)
            cin >> popSequence[j];

        bool flag = true;
        int j = 1;
        int h = 1;
        while (!st.empty())
            st.pop();

        for (h = 1; h <= N; h++) {
            st.push(h);
            if (st.size() > M) {
                flag = false;
                break;
            }
            while (!st.empty() && st.top() == popSequence[j]) {
                j++;
                st.pop();
            }
        }
        if (st.empty() && flag) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
}