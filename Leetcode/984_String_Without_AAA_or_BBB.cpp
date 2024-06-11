class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        while (a > 0 || b > 0) {
            if (a > b) {
                if (ans.size() < 2 || !(ans.back() == 'a' && ans[ans.size()-2] == 'a')) {
                    ans += 'a';
                    a--;
                }
                else if (b > 0) {
                    ans += 'b';
                    b--;
                }
            }
            else {
                if (ans.size() < 2 || !(ans.back() == 'b' && ans[ans.size()-2] == 'b')) {
                    ans += 'b';
                    b--;
                }
                else if (a > 0) {
                    ans += 'a';
                    a--;
                }
            }
        }
        return ans;
    }
};