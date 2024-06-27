class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> m;
        for (auto e: edges) {
            m[e[0]]++;
            m[e[1]]++;
        }
        auto pr = max_element(m.begin(), m.end(), 
            [] (const pair<int, int>& p1, const pair<int, int>& p2) {
                return p1.second < p2.second;
            }
        );
        return pr->first;
    }
};