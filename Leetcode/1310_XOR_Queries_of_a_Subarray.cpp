class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), i = 0;
        vector<int> pf(arr.begin(), arr.end()), ans(queries.size(), 0);
        for (int i = 1; i < n; i++) pf[i] ^= pf[i-1];
        for (auto q: queries) ans[i++] = pf[q[1]] ^ (q[0] == 0 ? 0 : pf[q[0]-1]);
        return ans;
    }
};
