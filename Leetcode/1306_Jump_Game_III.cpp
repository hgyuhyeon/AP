class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        int n = arr.size();
        vector<bool> dp(n, false);
        dp[start] = true;
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            if (arr[idx] == 0) return true;
            if (idx - arr[idx] >= 0 && !dp[idx-arr[idx]]) {
                q.push(idx-arr[idx]);
                dp[idx-arr[idx]] = true;
            }
            if (idx + arr[idx] < n && !dp[idx+arr[idx]]) {
                q.push(idx+arr[idx]);
                dp[idx+arr[idx]] = true;
            }
        }
        return false;
    }
};