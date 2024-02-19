class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, flag = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || flag == 1) {
            if (i >= 0) flag += (a[i--] - '0');
            if (j >= 0) flag += (b[j--] - '0');
            ans += to_string(flag % 2);
            flag /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};