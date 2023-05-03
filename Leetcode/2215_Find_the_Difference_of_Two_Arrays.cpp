class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        vector<int> ans1, ans2;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        for (auto i: s1) if (s2.count(i) == 0) ans1.push_back(i);
        for (auto j: s2) if (s1.count(j) == 0) ans2.push_back(j);
        
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};