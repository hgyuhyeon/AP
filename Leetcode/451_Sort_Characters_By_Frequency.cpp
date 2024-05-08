class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for (auto c: s) m[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto [c, i]: m) pq.push({i, c});
        s = "";
        while (!pq.empty()) {
            int i = 0;
            while (i++ < pq.top().first) s += pq.top().second;
            pq.pop();
        }
        return s;
    }
};