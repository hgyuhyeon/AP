/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(map<int, Employee*>& emp, int cur, int& ans) {
        for (auto e: emp[cur]->subordinates) dfs(emp, e, ans);
        ans += emp[cur]->importance;
    }
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> m;
        for (auto e: employees) m[e->id] = e;
        int ans = 0;
        dfs(m, id, ans);
        return ans;
    }
};
