class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int> v1, vector<int> v2){
            if (v1[1] != v2[1]) return v1[1] < v2[1];
            else return v1[2] < v2[2];
        });
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        int cap = 0;
        for (auto t: trips) {
            while (!pq.empty() && pq.top()[0] <= t[1]) {
                cap -= pq.top()[1];
                pq.pop();
            }
            if (cap + t[0] > capacity) return false;
            cap += t[0];
            pq.push({t[2], t[0]});
        }
        return true;
    }
};