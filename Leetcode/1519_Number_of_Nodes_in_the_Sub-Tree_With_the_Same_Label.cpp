class Solution {
public:
    void dfs(vector<vector<int>>& e, vector<vector<int>>& m, int cur, int p, string& labels) {
        m[cur][labels[cur]-'a']++;
        for (auto next: e[cur]) {
            if (next != p) {
                dfs(e, m, next, cur, labels);
                for (int i = 0; i < 26; i++) m[cur][i] += m[next][i];
            }
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> eg(n, vector<int>());
        for (auto e: edges) {
            eg[e[0]].push_back(e[1]);
            eg[e[1]].push_back(e[0]);
        }
        vector<int> ans(n, 0);
        vector<vector<int>> m(n, vector<int>(26, 0));
        dfs(eg, m, 0, 0, labels);
        for (int i = 0; i < n; i++) ans[i] = m[i][labels[i]-'a'];
        return ans;
    }
};