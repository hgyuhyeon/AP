#include <bits/stdc++.h>

using namespace std;

int main() {
    cout <<"#" << test_case << " ";

    string str;
    cin >> str;
    bool flag = true;
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length()-1-i]) {
        	flag = false;
            break;
        }
    }
            
    if (flag) cout << 1 << endl;
    else cout << 0 << endl;
    
    return 0;
}