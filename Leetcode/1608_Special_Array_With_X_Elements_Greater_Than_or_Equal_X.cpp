class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), cnt;
        for (int i = 1; i <= n; i++) {
            cnt = 0;
            for (int j = n-1; j >= 0; j--) {
                if (nums[j] >= i) cnt++;
                else break;
            }
            if (i == cnt) return i;
        }
        return -1;
    }
};