class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size() / 3, cnt = 0, ans = 0;
        for (int i = piles.size() - 2; cnt < n; cnt++, i-=2) ans += piles[i];
        return ans;
    }
};