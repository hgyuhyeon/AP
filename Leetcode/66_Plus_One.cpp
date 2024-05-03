class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        vector<int> ans(1, 1);
        ans.insert(ans.end(), digits.begin(), digits.end());
        return ans;
    }
};