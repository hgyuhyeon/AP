class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> s(n), choose(n, 0);
        for (int i = 0; i < n; i++) s[i] = i + 1;
        for (int i = 0; i < k; i++) choose[i] = 1;

        do {
            vector<int> temp;
            for (int i = 0; i < s.size(); i++)
                if (choose[i]) temp.push_back(s[i]);
            ans.push_back(temp);
        } while (prev_permutation(choose.begin(), choose.end()));

        return ans;
    }
};