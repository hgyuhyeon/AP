class Solution {
public:
    vector<int> val;
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int idx, int target) {
        if (target <= 0 || idx == candidates.size()) {
            if (target == 0 && find(ans.begin(), ans.end(), val) == ans.end()) ans.push_back(val); 
            return;
        }
        val.push_back(candidates[idx]);
        solve(candidates, idx+1, target-candidates[idx]);
        val.pop_back();
        int idx2 = idx;
        while (idx2 < candidates.size() && candidates[idx] == candidates[idx2]) idx2++;
        solve(candidates, idx2, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target);
        return ans;
    }
};
