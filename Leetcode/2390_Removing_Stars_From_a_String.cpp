class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        for (auto c: s) {
            switch(c) {
                case '*':
                    if (!stk.empty()) stk.pop();
                    break;
                default:
                    stk.push(c);
            }
        }

        string ans;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};