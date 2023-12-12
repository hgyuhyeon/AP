class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num1_idx = max_element(nums.begin(), nums.end()) - nums.begin();
        int num1 = nums[num1_idx] - 1;
        nums[num1_idx] = 0;
        int num2 = *max_element(nums.begin(), nums.end()) - 1;
        return num1 * num2;
    }
};