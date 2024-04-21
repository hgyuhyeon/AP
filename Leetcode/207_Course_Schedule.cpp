class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<int>& v, int i) {
        v[i] = 1;
        for (auto cur: g[i]) if (v[cur] == 1 || (v[cur] == 0 && !dfs(g, v, cur))) return false;
        v[i] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        vector<int> v(numCourses, 0);
        for (auto p: prerequisites) g[p[1]].push_back(p[0]);
        for (int i = 0; i < numCourses; i++) {
            if (v[i] == 2) continue;
            if (!dfs(g, v, i)) return false;
        }
        return true;
    }
};