class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] < nums[hi]) hi = mid;
            else lo = mid + 1;
        }
        return nums[lo];
    }
};
