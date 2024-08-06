class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        else {
            string cur = countAndSay(n-1), ans = "";
            char cha = cur[0];
            int cnt = 1;
            for (int i = 1; i < cur.size(); i++) {
                if (cha != cur[i]) {
                    ans += (char)(cnt + '0');
                    ans += cha;
                    cha = cur[i];
                    cnt = 1;
                }
                else cnt++;
            }
            ans += (char)(cnt + '0');
            ans += cha;
            return ans;
        }
    }
};
