#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

int main() {
    string word;
    stack<string> st;
    while (cin >> word) {
        st.push(word);
    }
    for (int i = st.size(); i > 1; i--) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << st.top() << endl;
    st.pop();
}