class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> s;
        map<int, int> m;
        for (auto i: trust) {
            s.insert(i[0]);
            m[i[1]]++;
        }
        if (s.size() == n) return -1;
        for (int i = 1; i <= n; i++) if(m[i] == n - 1) return i;
        return -1;
    }
};