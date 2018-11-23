#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int change[54];
string cards[54] = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8",
                    "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "J1", "J2"};
string temp[54];
int main() {
    /*
    char num[5];
    for (int i = 0; i < 13; i++) {
        itoa(i + 1, num, 10);
        string str(num);
        cards[i] = "S" + str;
        // cout << cards[i] << ' ';
    }
    for (int i = 13; i < 26; i++) {
        itoa(i - 12, num, 10);
        string str(num);
        cards[i] = "H" + str;
    }
    for (int i = 26; i < 39; i++) {
        itoa(i - 25, num, 10);
        string str(num);
        cards[i] = "C" + str;
    }
    for (int i = 39; i < 52; i++) {
        itoa(i - 38, num, 10);
        string str(num);
        cards[i] = "D" + str;
    }
    cards[52] = "J1";
    cards[53] = "J2";

    for (int i = 0; i < 64; i++) {
        cout << cards[i] << ' ';
    }
    */

    int n;
    cin >> n;
    for (int i = 0; i < 54; i++) {
        cin >> change[i];
        change[i]--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 54; j++) {
            int pos = change[j];
            temp[pos] = cards[j];
        }
        for (int j = 0; j < 54; j++) {
            cards[j] = temp[j];
        }
    }

    for (int i = 0; i < 54; i++) {
        cout << cards[i];
        if (i != 53) {
            cout << ' ';
        }
    }
}