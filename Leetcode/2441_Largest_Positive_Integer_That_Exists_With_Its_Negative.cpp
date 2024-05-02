class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        while (i < j && nums[i] < 0 && nums[j] > 0) {
            if (abs(nums[i]) > abs(nums[j])) i++;
            else if (abs(nums[i]) < abs(nums[j])) j--;
            else return nums[j];
        }
        return -1;
    }
};