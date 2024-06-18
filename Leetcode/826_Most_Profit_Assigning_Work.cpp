class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> v;
        for (int i = 0, n = profit.size(); i < n; i++) v.push_back({difficulty[i], profit[i]});
        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
            if (a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });
        int ans = 0;
        for (auto w: worker) {
            for (auto p: v) {
                if (p.first <= w) {
                    ans += p.second;
                    break;
                }
            }
        }
        return ans;
    }
};