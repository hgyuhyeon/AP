class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        map<int, int> m;
        for (auto i: nums) m[i]++;
        for (auto [i, v]: m) if (v == 1) ans.push_back(i);
        return ans;
    }
};