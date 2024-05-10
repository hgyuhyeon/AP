class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<>> pq;
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                pq.push({(float)arr[i]/(float)arr[j], {arr[i], arr[j]}});
            }
        }
        for (int i = 0; i < k-1 && !pq.empty(); i++) pq.pop();
        return vector<int>{pq.top().second.first, pq.top().second.second};
    }
};