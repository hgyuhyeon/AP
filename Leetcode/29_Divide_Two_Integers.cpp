class Solution {
public:
    int divide(int dividend, int divisor) {
        long ans = (long)dividend / (long)divisor;
        if (ans < INT_MIN) return INT_MIN;
        if (ans > INT_MAX) return INT_MAX;
        return ans;
    }
};
