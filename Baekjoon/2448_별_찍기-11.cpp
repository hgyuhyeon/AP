#include <bits/stdc++.h>

using namespace std;

int n, col;
vector<vector<char>> v;

void search(int rlo, int rhi, int clo, int chi) {
    if (rlo >= rhi || clo >= chi) return;
    int rlen = rhi - rlo, rdiv = rlen / 2;
    int clen = chi - clo, cdiv = clen / 2;
    if (rlen == 3 && clen == 6) {
        v[rlo][clo+2] = '*';
        
        v[rlo+1][clo+1] = '*';
        v[rlo+1][clo+3] = '*';
        
        v[rlo+2][clo] = '*';
        v[rlo+2][clo+1] = '*';
        v[rlo+2][clo+2] = '*';
        v[rlo+2][clo+3] = '*';
        v[rlo+2][clo+4] = '*';
        return;
    }
    // 1
    search(rlo, rlo + rdiv, clo + cdiv / 2, clo + cdiv + cdiv / 2);

    // 2
    search(rlo + rdiv, rhi, clo, clo + cdiv);
    search(rlo + rdiv, rhi, clo + cdiv, chi);
}

int main() {
    cin >> n;
    col = n / 3 * 6;
    v = vector<vector<char>>(n, vector<char>(col, ' '));
    search(0, n, 0, col);
    for (auto i: v) {
        for (auto j: i) cout << j;
        cout << '\n';
    }
    return 0;
}
