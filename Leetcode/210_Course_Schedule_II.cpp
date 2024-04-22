class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<int>& p, vector<int>& ans, int index) {
        ans.push_back(index);
        p[index] = -1;
        for (auto i: g[index]) if (--p[i] == 0) dfs(g, p, ans, i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> preq(numCourses), ans;
        
        for (auto p: prerequisites) {
            g[p[1]].push_back(p[0]);
            preq[p[0]]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (preq[i] == 0) dfs(g, preq, ans, i);
        }
        
        if (ans.size() == numCourses) return ans;
        else return {};
    }
};