class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                string ans = word.substr(0, i+1);
                reverse(ans.begin(), ans.end());
                ans += word.substr(i+1);
                return ans;
            }
        }
        return word;
    }
};