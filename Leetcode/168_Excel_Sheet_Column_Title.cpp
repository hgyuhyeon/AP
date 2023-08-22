class Solution {
public:
    string convertToTitle(int columnNumber) {
        int cnum = columnNumber;
        string ans = "";
        while (cnum > 0) {
            int val = cnum % 26;
            if (val == 0) {
                val = 26;
                cnum--;
            }
            ans = (char)(64 + val) + ans;
            cnum /= 26;
        }
        return ans;
    }
};