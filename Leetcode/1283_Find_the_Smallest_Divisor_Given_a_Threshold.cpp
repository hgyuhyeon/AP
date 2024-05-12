class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 1e6;
        while (lo < hi) {
            int mid = (lo+hi)/2, sum = 0;
            for (auto i: nums) sum += (i / mid + (i % mid != 0 ? 1 : 0));
            if (sum <= threshold) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};