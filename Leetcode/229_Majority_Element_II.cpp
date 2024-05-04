class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int, int> m;
        int n = nums.size();
        for (auto i: nums) {
            if (m[i] == -1) continue;
            if (++m[i] > n / 3) {
                ans.push_back(i);
                m[i] = -1;
            }
        }
        return ans;
    }
};