class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size();
        for (auto num: nums) {
            if (++m[num] > n / 2) return num;
        }
        return nums[0];
    }
};