class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<int>> m;
        unordered_set<string> sorted;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(i);
            sorted.insert(tmp);
        }
        for (auto iter = sorted.begin(); iter != sorted.end(); iter++) {
            vector<string> str;
            for (int i: m[*iter]) str.push_back(strs[i]);
            ans.push_back(str);
        }
        return ans;
    }
};