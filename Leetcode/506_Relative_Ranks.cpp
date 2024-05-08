class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        int n = score.size();
        for (int i = 0; i < n; i++) pq.push({score[i], i});
        vector<string> ans(n);
        int r = 1;
        while (!pq.empty()) {
            if (r == 1) ans[pq.top().second] = "Gold Medal";
            else if (r == 2) ans[pq.top().second] = "Silver Medal";
            else if (r == 3) ans[pq.top().second] = "Bronze Medal";
            else ans[pq.top().second] = to_string(r);
            pq.pop();
            r++;
        }
        return ans;
    }
};