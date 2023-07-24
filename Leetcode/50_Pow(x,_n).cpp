class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if (n == 0) return ans;
        if (x == 0) return 0;
        else if (x == 1 || (x == -1 && n % 2 == 0)) return 1;
        else if (x == -1) return -1; 

        if (n < 0) x = 1 / x;

        if (n == INT_MIN) n++;
        for (int i = 0; i < abs(n); i++) {
            ans *= x;
            if (ans > 10000 || ans == 0) break;
        }
        return ans;
    }
};