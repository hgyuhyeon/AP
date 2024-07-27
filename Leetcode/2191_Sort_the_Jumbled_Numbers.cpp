class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> m;

        for (int i = 0; i < n; i++) {
            int mul = 1, tmp = nums[i], mnum = 0;
            if (tmp == 0) {
                mnum = mapping[0];
            }
            else {
                while (tmp > 0) {
                    mnum += mapping[tmp % 10] * mul;
                    mul *= 10;
                    tmp /= 10;
                }
            }
            m.push_back({mnum, i});
        }
        sort(m.begin(), m.end());

        vector<int> ans;
        for (int i = 0; i < n; i++) ans.push_back(nums[m[i].second]);
        return ans;
    }
};
