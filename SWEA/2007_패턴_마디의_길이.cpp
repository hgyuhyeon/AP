#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;

    for (int len = 1; len <= 10; len++) {
        string s1 = s.substr(len), s2 = s.substr(len, len);
        if (s1 == s2) {
            cout << len << endl;
            break;
        }
    }
    
    return 0;
}