#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
vector<vector<char>> v;

void search(int rlo, int rhi, int clo, int chi) {
    if (rlo >= rhi || clo >= chi) return;
    int rlen = rhi - rlo, rdiv = rlen / 3;
    int clen = chi - clo, cdiv = clen / 3;
    if (rlen == 1 && clen == 1) {
        v[rlo][clo] = '*';
        return;
    }
    search(rlo, rlo + rdiv, clo, clo + cdiv);
    search(rlo + rdiv, rlo + rdiv*2, clo, clo + cdiv);
    search(rlo + rdiv*2, rhi, clo, clo + cdiv);
    
    search(rlo, rlo + rdiv, clo + cdiv, clo + cdiv*2);
    // 가운데는 제외
    search(rlo + rdiv*2, rhi, clo + cdiv, clo + cdiv*2);
    
    search(rlo, rlo + rdiv, clo + cdiv*2, chi);
    search(rlo + rdiv, rlo + rdiv*2, clo + cdiv*2, chi);
    search(rlo + rdiv*2, rhi, clo + cdiv*2, chi);
}

int main() {
    cin >> n;
    v = vector<vector<char>>(n, vector<char>(n, ' '));
    search(0, n, 0, n);
    for (auto i: v) {
        for (auto j: i) cout << j;
        cout << '\n';
    }
    return 0;
}
