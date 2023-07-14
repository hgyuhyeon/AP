class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int ans = 1;
        map<int, int> m;
        for (auto i: arr) {
            m[i] = 1 + m[i - diff];
            if (ans < m[i]) ans = m[i];
        }        
        return ans;
    }
};