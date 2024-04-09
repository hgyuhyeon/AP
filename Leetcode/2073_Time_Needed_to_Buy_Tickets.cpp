class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++) q.push({i, tickets[i]});
        while (!q.empty()) {
            ans++;
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i == k && j == 1) break;
            if (j-1 > 0) q.push({i, j-1});
        }
        return ans;
    }
};