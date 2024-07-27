class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> fw(26, vector<int>(26, 1e7));
        int n = original.size();
        for (int i = 0; i < n; i++) {
            fw[original[i]-'a'][changed[i]-'a'] = min(fw[original[i]-'a'][changed[i]-'a'], cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
                }
            }
        }

        n = source.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (source[i] != target[i]) {
                if (fw[source[i] - 'a'][target[i] - 'a'] == 1e7) return -1;
                ans += fw[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return ans;
    }
};