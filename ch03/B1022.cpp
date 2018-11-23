#include <iostream>
#include <stack>

using namespace std;

int main() {
    int a, b, d;
    int sum, res = 0;
    while (cin >> a >> b >> d) {
        sum = a + b;
        stack<int> st;
        do {
            st.push(sum % d);
            sum = sum / d;
        } while (sum != 0);
        for (int i = st.size(); i > 0; i--) {
            cout << st.top();
            st.pop();
        }
    }
}