class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while (s != "1") {
            if (s.back() == '1') {
                for (int i = s.size() - 1; i >= 0; i--) {
                    if (s[i] == '1') {
                        s[i] = '0';
                        if (i == 0) s = '1' + s;
                    }
                    else {
                        s[i] = '1';
                        break;
                    }
                }
            }
            else s.pop_back();
            ans++;
        }
        return ans;
    }
};