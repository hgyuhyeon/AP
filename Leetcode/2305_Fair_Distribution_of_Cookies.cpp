class Solution {
public:
    int ans = INT_MAX;
    void search(vector<int>& cookies, vector<int>& d, int idx) {
        if (idx == cookies.size()) {
            ans = min(ans, *max_element(d.begin(), d.end()));
            return;
        }
        for (int i = 0; i < d.size(); i++) {
            d[i] += cookies[idx];
            search(cookies, d, idx+1);
            d[i] -= cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dist(k, 0);
        search(cookies, dist, 0);
        return ans;
    }
};
