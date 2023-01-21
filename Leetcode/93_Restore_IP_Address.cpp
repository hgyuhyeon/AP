class Solution {
public:
    bool isValid(string s) {
        if (stoi(s) > 255 || (s.size() >= 2 && s[0] == '0')) return false;
        return true;
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.size() < 4 || s.size() > 12) return ans;

        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    if (i+j+k < s.size() && i+j+k+3 >= s.size()) {
                        string s1 = s.substr(0, i);
                        string s2 = s.substr(i, j);
                        string s3 = s.substr(i+j, k);
                        string s4 = s.substr(i+j+k);
                        if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                            ans.push_back(s1+"."+s2+"."+s3+"."+s4);
                        }
                    }
                }
            }
        }

        return ans;
    }
};