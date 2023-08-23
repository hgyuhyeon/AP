class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        vector<int> m(26, 0);
        for (auto c: s) {
            m[c - 'a']++;
            if (m[c - 'a'] > (s.size() + 1) / 2) return ans;
        }

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) if (m[i]) pq.push({m[i], char(i) + 'a'});

        pair <int, char> p1, p2;
        while (pq.size() >= 2) {
            p1 = pq.top();
            pq.pop();
            p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;
            if (p1.first > 1) pq.push({p1.first - 1, p1.second});
            if (p2.first > 1) pq.push({p2.first - 1, p2.second});
        }

        if (!pq.empty()) ans += pq.top().second;

        return ans;
    }
};