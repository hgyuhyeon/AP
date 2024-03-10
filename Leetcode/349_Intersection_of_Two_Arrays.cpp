class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        unordered_set<int> s;
        for (auto i: nums1) m[i]++;
        for (auto i: nums2) if (m[i] > 0) s.insert(i);
        return vector<int>(s.begin(), s.end());
    }
};