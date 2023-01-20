class Solution {
public:
    map<int, vector<int>> row, col;
    set<int> visited;
    
    int removeStones(vector<vector<int>>& stones) {
        int cnt = 0;
        
        for (int i = 0; i < stones.size(); i++) {
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }
        
        function<int(int)> dfs = [&](int i) -> int {
            if (visited.count(i)) return 0;
            visited.insert(i);
            int r = stones[i][0], c = stones[i][1];
            for (auto ss : row[r]) dfs(ss);
            for (auto ss : col[c]) dfs(ss);
            return 1;
        };
        
        for (int i = 0; i < stones.size(); i++) cnt += dfs(i);
        
        return stones.size() - cnt;
    }
};