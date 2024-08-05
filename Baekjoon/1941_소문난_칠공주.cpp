#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> board;
int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};
int p[5][5] = { false, };
int ans = 0;

int search(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    int cnt = 1;
    bool v[5][5] = { false, };
    v[i][j] = true;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && !v[nr][nc] && p[nr][nc]) {
                v[nr][nc] = true;
                q.push({nr, nc});
                cnt++;
            }
        }
    }
    if (cnt == 7) return 1;
    else return 0;
}

void comb(int i, int cnt, int rem, pair<int, int> init) {
    if (cnt == 7) {
        ans += search(init.first, init.second);
        return;
    }
    if (i == 25) return;
    int x = i / 5, y = i % 5;
    if (board[x][y] == 'S') {
        p[i / 5][i % 5] = true;
        comb(i+1, cnt+1, rem, {x, y});
        p[i / 5][i % 5] = false;
    }
    if (board[x][y] == 'Y' && rem > 0) {
        p[i / 5][i % 5] = true;
        comb(i+1, cnt+1, rem-1, {x, y});
        p[i / 5][i % 5] = false;
    }
    comb(i+1, cnt, rem, init);
}

int main() {
    board = vector<vector<char>>(5, vector<char>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    comb(0, 0, 3, {0, 0});
    cout << ans;

    return 0;
}
