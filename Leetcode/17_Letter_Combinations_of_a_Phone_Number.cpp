class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string>();
        vector<string> v = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        }, ans{ "" };

        for (auto n: digits) {
            vector<string> tmp;
            for (auto c: v[n - '0']) {
                for (auto s: ans) tmp.push_back(s + c);
            }
            ans = tmp;
        }

        return ans;
    }
};