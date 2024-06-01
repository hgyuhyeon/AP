class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int, int> m;
        for (auto b: barcodes) m[b]++;
        priority_queue<pair<int, int>> pq;
        for (auto [i, v]: m) pq.push({v, i});
        vector<int> ans;
        while (!pq.empty()) {
            auto [f, num] = pq.top();
            pq.pop();
            if (ans.empty() || ans.back() != num) {
                ans.push_back(num);
                f--;
            }
            else {
                auto [f2, num2] = pq.top();
                pq.pop();
                ans.push_back(num2);
                if (f2-1) pq.push({f2-1, num2});
            }
            if (f > 0) pq.push({f, num});
        }
        return ans;
    }
};