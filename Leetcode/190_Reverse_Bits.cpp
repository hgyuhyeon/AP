class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int d = 31; d >= 0; d--, n >>= 1) ans += (n % 2) << d;
        return ans;
    }
};