class Solution {
public:
    int reverse(int x) {
        int ans = 0, mul = x >= 0? 1: -1;
        x = abs(x);
        while (x > 0) {
            if (ans > INT_MAX / 10) return 0;
            ans = (ans * 10) + x % 10;
            x /= 10;
        }
        return ans * mul;
    }
};
