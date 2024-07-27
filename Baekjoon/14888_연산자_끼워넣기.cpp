#include <bits/stdc++.h>
using namespace std;

int n, ans_max = INT_MIN, ans_min = INT_MAX;
vector<int> v, op(4);

void solve(int idx, int val) {
    if (idx == n) {
        ans_max = max(val, ans_max);
        ans_min = min(val, ans_min);
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (op[i] > 0) {
                op[i]--;
                if (i == 0) solve(idx+1, val + v[idx]);
                if (i == 1) solve(idx+1, val - v[idx]);
                if (i == 2) solve(idx+1, val * v[idx]);
                if (i == 3 && v[idx] != 0) solve(idx+1, val / v[idx]);
                op[i]++;
            }
        }
        
    }
}

int main() {
    
    cin >> n;
    v = vector<int>(n, 0);

    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < 4; i++) cin >> op[i];
    solve(1, v[0]);
    
    cout << ans_max << endl << ans_min;
    return 0;
}
