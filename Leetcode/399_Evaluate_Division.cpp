class Solution {
public:
    double bfs(unordered_map<string, vector<pair<string, double>>>& g, string src, string dest) {
        queue<pair<string, double>> q;
        unordered_map<string, int> v;
        q.push({src, 1});
        v[src]++;
        while (!q.empty()) {
            string cur = q.front().first;
            double val = q.front().second;
            if (cur == dest) return val;
            for (auto c: g[cur]) {
                if (!v[c.first]) {
                    v[c.first]++;
                    q.push({c.first, val * c.second});
                }
            }
            q.pop();
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> v;
        unordered_map<string, vector<pair<string, double>>> g;
        for (int i = 0, n = equations.size(); i < n; i++) {
            v[equations[i][0]]++;
            v[equations[i][1]]++;
            g[equations[i][0]].push_back({equations[i][1], values[i]});
            g[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        
        vector<double> ans;
        for (auto q: queries) {
            if (!v[q[0]] || !v[q[1]]) ans.push_back(-1.0);
            else if (q[0] == q[1]) ans.push_back(1.0);
            else ans.push_back(bfs(g, q[0], q[1]));
        }
        return ans;
    }
};