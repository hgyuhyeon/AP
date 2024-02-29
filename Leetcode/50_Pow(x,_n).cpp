class Solution {
public:
    double solve(double x, int n) {
        if (n == 1 || n == -1) return x;
        else if (n == 0) return 1;
        double ans = solve(x, n / 2);
        return ans * ans * ((n%2) == 0 ? 1 : x);
    }
    double myPow(double x, int n) {
        if (n < 0) x = 1 / x;
        return solve(x, n);
    }
};