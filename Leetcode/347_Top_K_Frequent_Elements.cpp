class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto i: nums) m[i]++;
        priority_queue<pair<int, int>> pq;
        for (auto [i, cnt]: m) pq.push({cnt, i});
        vector<int> ans;
        for (int i = 0; i < k && !pq.empty(); i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};