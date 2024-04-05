class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for (auto c: s) {
            if (!stk.empty() && (stk.top() == (char)(c - 32) || stk.top() == (char)(c + 32))) stk.pop();
            else stk.push(c);
        }
        string ans = "";
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};