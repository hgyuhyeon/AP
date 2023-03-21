class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0, res = 0;
        for (auto i: nums) {
            if (i == 0) cnt++;
            else {
                long long n = 1;
                while (cnt > 0) {
                    res += n++;
                    cnt--;
                }
            }
        }

        long long n = 1;
        while (cnt > 0) {
            res += n++;
            cnt--;
        }
        return res;
    }
};