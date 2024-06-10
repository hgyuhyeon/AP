class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> ex(heights.begin(), heights.end());
        sort(ex.begin(), ex.end());
        int ans = 0, n = ex.size();
        for (int i = 0; i < n; i++) if (ex[i] != heights[i]) ans++;
        return ans;
    }
};