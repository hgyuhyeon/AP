class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        map<int, int> m;
        for (auto i: nums) if (++m[i] > 1) ans.push_back(i);
        return ans;
    }
};