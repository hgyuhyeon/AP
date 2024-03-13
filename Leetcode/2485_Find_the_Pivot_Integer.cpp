class Solution {
public:
    int pivotInteger(int n) {
        int val = 1, sum = n * (n+1) / 2, total = 0;
        while (val <= n) {
            total += val;
            if (total == sum + val - total) break;
            else val++;
        }
        return val > n ? -1 : val;
    }
};