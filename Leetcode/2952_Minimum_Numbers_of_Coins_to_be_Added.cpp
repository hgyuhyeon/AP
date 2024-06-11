class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        long long sum = 0;
        for (auto c: coins) {
            while (c > sum + 1) {
                ans++;
                sum += (sum + 1);
            }
            sum += c;
        }
        while (sum < target) {
            sum += (sum + 1);
            ans++;
        }
        return ans;
    }
};