class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int num = 1; num <= n && num > 0; num = num << 1) {
            if (n == num) return true;
        }
        return false;
    }
};