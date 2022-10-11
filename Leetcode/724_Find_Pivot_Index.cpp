class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lsum = 0, rsum = 0;
        
        for (auto i: nums) {
            rsum += i;
        }
        rsum -= nums[0];
        
        for (int idx = 0; idx < nums.size() - 1; idx++) {
            if (lsum == rsum) {
                return idx;
            }
            else {
                lsum += nums[idx];
                rsum -= nums[idx+1];
            }
        }
        
        if (lsum == rsum)
            return nums.size()-1;
        else
            return -1;
    }
};