#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node {
    bool flag;  // true-operand  false-operator
    double num;
    char op;
};

string str;     // expression input
stack<node> operators;
queue<node> expr;       // postfix expression
map<char, int> mp;

void Change() {
    node temp;
    double num;
    for (int i = 0; i < str.length();) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp.flag = true;
            temp.num = str[i++] - '0';
            while (str[i] >= '0' && str[i] <= '9') {
                temp.num = temp.num * 10 + (str[i++] - '0');
            }
            expr.push(temp);
        } else {
            temp.flag = false;
            while (!operators.empty() && mp[str[i]] <= mp[operators.top().op]) {
                expr.push(operators.top());
                operators.pop();
            }
            temp.op = str[i];
            operators.push(temp);
            i++;
        }
    }
    while (!operators.empty()) {
        expr.push(operators.top());
        operators.pop();
    }
}

double Calc() {
    double operand1, operand2;
    node curr, temp;
    while (!expr.empty()) {
        curr = expr.front();
        expr.pop();
        if (curr.flag)
            operators.push(curr);
        else {
            operand2 = operators.top().num;
            operators.pop();
            operand1 = operators.top().num;
            operators.pop();
            switch (curr.op) {
                case '+':
                    temp.num = operand1 + operand2;
                    break;
                case '-':
                    temp.num = operand1 - operand2;
                    break;
                case '*':
                    temp.num = operand1 * operand2;
                    break;
                case '/':
                    temp.num = operand1 / operand2;
                    break;
                default:
                    break;
            }
            operators.push(temp);
        }
    }
    return operators.top().num;
}

int main() {
    mp['+'] = mp['-'] = 1;
    mp['*'] = mp ['/'] = 2;
    getline(cin, str);
    for (string::iterator it = str.begin(); it != str.end(); it++) {
        if (*it == ' ')
            str.erase(it);
    }
    Change();
    // cout << str << endl;
    // while (!expr.empty()) {
    //     if (expr.front().flag)
    //         cout << expr.front().num;
    //     else
    //         cout << expr.front().op;
    //     expr.pop();
    // }
    cout << Calc() << endl;
}