class Solution {
public:
    int solve(string& s, string str) {
        stack<char> stk;
        int cnt = 0;
        for (auto c: s) {
            if (!stk.empty() && string() + stk.top() + c == str) {
                stk.pop();
                cnt++;
            }
            else stk.push(c);
        }
        s = "";
        while (!stk.empty()) {
            s += stk.top();
            stk.pop();
        }
        reverse(s.begin(), s.end());
        return cnt;
    }
    int maximumGain(string s, int x, int y) {
        
        string xstr = "ab", ystr = "ba";
        int ans = 0;
        if (x < y) {
            swap(x,y);
            swap(xstr, ystr);
        }
        ans += solve(s, xstr) * x;
        ans += solve(s, ystr) * y;                
        return ans;
    }
};