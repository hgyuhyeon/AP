class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        for (auto i: nums) if (++m[i] > 1) return i;
        return 1;
    }
};