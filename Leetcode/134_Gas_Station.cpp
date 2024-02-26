class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), total = 0, cir = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            total += (gas[i] - cost[i]);
            cir += (gas[i] - cost[i]);
            if (cir < 0) {
                ans = i+1;
                cir = 0;
            }
        }
        return total >= 0 ? ans : -1;
    }
};