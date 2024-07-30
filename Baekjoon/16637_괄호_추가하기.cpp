#include <bits/stdc++.h>

using namespace std;

int n, ans = INT_MIN;
string s;

int cal(int l, char op, int r) {
    switch(op) {
        case '+':
            return l + r;
        case '-':
            return l - r;
        case '*':
            return l * r;
        case '/':
            return l / r;
        default:
            break;
    }
    return 0;
}

void solve(int i, int val) {
    if (i == n) {
        ans = max(ans, val);
        return;
    }
    if (i <= n-4) solve(i+4, cal(val, s[i], cal(s[i+1]-'0', s[i+2], s[i+3]-'0')));
    solve(i+2, cal(val, s[i], s[i+1]-'0'));
}
int main() {
    cin >> n >> s;
    solve(1, s[0] - '0');
    cout << ans;

    return 0;
}
