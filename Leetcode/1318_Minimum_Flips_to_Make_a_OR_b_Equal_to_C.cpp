class Solution {
public:
    int minFlips(int a, int b, int c) {
        int val = a | b, ans = 0;
        while (val > 0 || c > 0) {
            if (val % 2 != c % 2) {
                if (c % 2 == 1) ans++;
                else {
                    if (a % 2 == 1 && b % 2 == 1) ans++;
                    ans++;
                }
            }
            val >>= 1;
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};
