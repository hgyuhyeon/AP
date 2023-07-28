class Solution {
public:
    bool search(vector<int>& nums, int p1, int p2, int sum1, int sum2) {
        if (p1 == p2) {
            if (sum1 > sum2) return true;
            else return false;
        }
        else return search(nums, p1+1, p2, sum1+nums[p1], sum2) || search(nums, p1, p2-1, sum1, sum2+nums[p2]);
    }
    bool PredictTheWinner(vector<int>& nums) {
        return search(nums, 0, nums.size(), 0, 0);
    }
};