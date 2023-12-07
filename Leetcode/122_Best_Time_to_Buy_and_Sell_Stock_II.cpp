class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, dip = prices[0], n = prices.size();
        for (int i = 1; i < n; i++) {
            if (prices[i-1] > prices[i]) {
                cout << prices[i-1] << endl;
                ans += (prices[i-1] - dip);
                dip = prices[i];
            }
            else if (prices[i] < dip) dip = prices[i];
        }
        if (prices[n - 1] > dip) ans += (prices[n - 1] - dip);
        return ans;
    }
};