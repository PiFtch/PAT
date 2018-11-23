#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "archangel";
    // cin >> str;
    cout << str;
    printf("%s\n", str.c_str());
    for (int i = 0; i < str.length(); i++)
        printf("%c", str[i]);

    putchar('\n');
    string::iterator it;
    for (it = str.begin(); it != str.end(); it++)
        printf("%c", *it);
    
    printf("\n");
    string str2 = "piftch";
    str.insert(0, str2);
    for (it = str.begin(); it != str.end(); it++)
        printf("%c", *it);
    cout << '\n' << str << endl;
    str.insert(str.begin() + 1, str2.begin(), str2.end());
    cout << str << endl;
    str.erase(str.begin());
    cout << str << endl;
    str.erase(str.begin()+6, str.begin() + 11);
    cout << str << endl;
    cout << str.substr(6, 9) << endl;
    if (str.find("you") == string::npos) {
        cout << "no such string" << endl;
    }
    int index;
    if ((index = str.find("archangel", 2)) != string::npos)
        cout << str.substr(index, 9) << endl;

    str.replace(6, 9, "piftch");
    cout << str << endl;
    str.replace(str.begin(), str.begin()+6, "archangel");
    cout << str << endl;
}