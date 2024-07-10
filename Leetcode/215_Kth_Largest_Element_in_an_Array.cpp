class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        for (auto i: nums) s.insert(i);
        auto itr = s.begin();
        for (int cnt = 0; cnt < s.size()-k; cnt++) itr++;
        return *itr;
    }
};
