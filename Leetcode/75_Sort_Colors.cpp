class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3, 0);
        for (auto i: nums) colors[i]++;
        for (int i = 0, j = 0; j < 3; j++) {
            while (colors[j]-- > 0) nums[i++] = j;
        }
    }
};