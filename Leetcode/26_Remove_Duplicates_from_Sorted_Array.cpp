class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for (auto n: nums) s.insert(n);
        int i = 0;
        for (auto iter: s) nums[i++] = iter;
        return s.size();
    }
};