class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (auto i: nums) {
            if (!s.insert(i).second) s.erase(i);
        }
        return *s.begin();
    }
};