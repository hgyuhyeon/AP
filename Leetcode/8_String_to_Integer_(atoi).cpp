class Solution {
public:
    int myAtoi(string s) {
        if (!s.size()) return 0;
        long long i = 0, ans = 0;
        while (s[i] == ' ') i++;
        if (i >= s.size()) return 0;
        int pn = s[i] == '-' ? -1 : 1;
        if (s[i] == '-' || s[i] == '+') i++;
        while (i < s.size()) {
            if (s[i] < '0' || s[i] > '9') break;
            int val = s[i++] - '0';
            ans = (ans * 10) + pn * val;
            if (ans < INT_MIN) return INT_MIN;
            if (ans > INT_MAX) return INT_MAX;
        }
        return ans;
    }
};
