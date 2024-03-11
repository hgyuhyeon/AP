class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> m;
        for (int i = 0; i < order.size(); i++) m[order[i]] = i;
        multiset<pair<int, char>> ms;
        for (int i = 0; i < s.size(); i++) ms.insert({m[s[i]], s[i]});
        vector<pair<int, char>> v(ms.begin(), ms.end());
        string ans = "";
        for (auto p: v) ans += p.second;
        return ans;
    }
};