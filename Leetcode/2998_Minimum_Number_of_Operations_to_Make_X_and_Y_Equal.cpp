class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (y >= x) return y - x;
        queue<pair<int, int>> q;
        map<int, int> dp;
        q.push({x, 0});
        while (!q.empty()) {
            auto [cur, cnt] = q.front();
            q.pop();
            if (cur == y) return cnt;
            else if (!dp[cur]) {
                dp[cur] = cnt;
                if (cur % 11 == 0 && !dp[cur%11]) q.push({cur / 11, cnt+1});
                if (cur % 5 == 0 && !dp[cur%5]) q.push({cur / 5, cnt+1});
                if (!dp[cur-1]) q.push({cur-1, cnt+1});
                if (!dp[cur+1]) q.push({cur+1, cnt+1});
            }
        }
        return x - y;
    }
};