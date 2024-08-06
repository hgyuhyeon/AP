class Solution {
public:
    int max_v = 0;
    map<int, int> m;
    void search(vector<int>& nums, int idx, int val) {
        if (idx == nums.size()) {
            max_v = max(max_v, val);
            m[val]++;
            return;
        }
        search(nums, idx+1, val | nums[idx]);
        search(nums, idx+1, val);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        search(nums, 0, 0);
        return m[max_v];
    }
};
