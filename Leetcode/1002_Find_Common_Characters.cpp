class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> v(26, words.size());
        for (auto word: words) {
            vector<int> tmp(26, 0);
            for (auto w: word) tmp[w-'a']++;
            for (int i = 0; i < 26; i++) v[i] = min(v[i], tmp[i]);
        }
        vector<string> ans;
        for (char c = 'a'; c <= 'z'; c++) {
            while (v[c-'a']-- > 0) ans.push_back(string(1, c)); 
        }
        return ans;
    }
};