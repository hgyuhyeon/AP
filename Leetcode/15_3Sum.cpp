class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        int one = 0, two = 1, three = 2;

        while (one < nums.size() - 2) {
            two = one + 1; three = nums.size() - 1;
            while (two < three) {
                if (nums[one] + nums[two] + nums[three] == 0) {
                    s.insert({nums[one], nums[two], nums[three]});
                    two++;
                    three--;
                }
                else if (nums[one] + nums[two] + nums[three] < 0) {
                    two++;
                }
                else three--;
            }
            one++;
        }

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};