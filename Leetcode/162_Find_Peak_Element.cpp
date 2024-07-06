class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 1, hi = nums.size() - 2, mid;
        if (nums.size() == 1) return 0;
        else if (nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;
        if (nums[0] > nums[1]) return 0;
        else if (nums[hi + 1] > nums[hi]) return hi+1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid]) return mid;
            else if (nums[mid+1] > nums[mid] && nums[mid] > nums[mid-1]) lo = mid + 1;
            else hi = mid - 1;
        }
        return mid;
    }
};