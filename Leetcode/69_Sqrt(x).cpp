class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int start = 1, end = x / 2;
        long long int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (mid * mid > x) end = mid - 1;
            else if (mid * mid - x == 0) return mid;
            else start = mid + 1;
        }
        return end;
    }
};