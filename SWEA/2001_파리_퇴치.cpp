#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> v[i][j];
    }

    int ans = 0;
    for (int i = 0; i < n - m; i++) {
        int sum = 0;
        for (int j = i; j < i + m; j++) {
            for (int k = i; k + m; k++) {
                sum += v[j][k];
            }
        }
        ans = max(ans, sum);
    }

    cout << ans;
    
    return 0;
}