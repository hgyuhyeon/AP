class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";

        queue<string> q;
        for (auto n: digits) {
            int num = (int)n - '0';
            if (q.empty()) {
                for (auto c: m[num]) {
                    string str = string(1, c);
                    q.push(str);
                }
            }
            else {
                int len = q.front().size();
                while (q.front().size() == len) {
                    for (auto c: m[num]) q.push(q.front() + c);
                    q.pop();
                }
            }
        }

        vector<string> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};