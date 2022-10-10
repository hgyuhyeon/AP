class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0, sum;
        for (auto i: accounts) {
            sum = 0;
            for (auto j: i) {
                sum += j;
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};