class Solution {
public:
    static bool cmp(string s1, string s2) {
        return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto i: nums) v.push_back(to_string(i));
        string ans = "";
        sort(v.begin(), v.end(), cmp);
        if (v[0] == "0") return v[0];
        for (auto c: v) ans += c;
        return ans;
    }
};