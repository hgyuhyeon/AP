class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), ptr = strs[0].size();
        sort(strs.begin(), strs.end());
        
        if (strs.size() < 2) return strs[0];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] != strs[0][j]) {
                    ptr = j;
                    break;
                }
            }
        }
        
        return strs[0].substr(0, ptr);
    }
};
