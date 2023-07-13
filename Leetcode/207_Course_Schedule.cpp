class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<int>& v, int i) {
        v[i] = 1;
        for (auto cur: g[i]) {
            if ((v[cur] == 0 && !dfs(g, v, cur)) || v[cur] == 1) return false;
        }
        v[i] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> visited(numCourses, 0);

        for (auto p: prerequisites) {
            g[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 2) continue;
            else if (!dfs(g, visited, i)) return false;
        }

        return true;
    }
};