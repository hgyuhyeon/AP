class Solution {
public:
    int totalMoney(int n) {
        int r = n / 7, ans = 0;
        for (int i = 0; i < r; i++) ans += (28 + i * 7);
        for (int i = 1; i <= n % 7; i++) ans += (i + r);
        return ans;
    }
};