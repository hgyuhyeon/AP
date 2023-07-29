class Solution {
public:
    bool search(vector<int>& nums, bool flag, int p1, int p2, int sum1, int sum2) {
        if (p1 > p2) {
            return sum1 >= sum2;
        }

        if (flag)  // p1 turn
            return search(nums, false, p1+1, p2, sum1+nums[p1], sum2) || search(nums, false, p1, p2-1, sum1+nums[p2], sum2);
        else // p2 turn
            return search(nums, true, p1+1, p2, sum1, sum2+nums[p1]) && search(nums, true, p1, p2-1, sum1, sum2+nums[p2]);
    }
    bool PredictTheWinner(vector<int>& nums) {
        return search(nums, true, 0, nums.size()-1, 0, 0);
    }
};