class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), diff = 0, rem = 0, res = 0;
        for (int i = 0; i < n; i++) {
            diff += (gas[i] - cost[i]);
            rem += (gas[i] - cost[i]);
            if (rem < 0) {
                res = i + 1;
                rem = 0;
            }
        }
        return (diff < 0) ? -1 : res;
    }
};