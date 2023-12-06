class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, dip = INT_MAX;
        for (auto i: prices) {
            dip = min(dip, i);
            ans = max(ans, i - dip);
        }
        return ans;
    }
};