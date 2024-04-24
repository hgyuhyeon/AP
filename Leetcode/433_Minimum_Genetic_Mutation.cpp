class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        map<string, int> b;
        for (auto s: bank) b[s]++;
        vector<char> c{'A','C','G','T'};
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        while (!q.empty()) {
            string s = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (s == endGene) return cnt;
            for (int i = 0; i < 8; i++) {
                string tmp = s;
                for (auto j = 0; j < 4; j++) {
                    tmp[i] = c[j];
                    if (s != tmp && b[tmp] > 0) {
                        q.push({tmp, cnt+1});
                        b[tmp]--;
                    }
                }
            }
        }
        return -1;
    }
};