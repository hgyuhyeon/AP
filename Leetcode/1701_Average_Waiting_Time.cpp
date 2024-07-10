class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        long long sum = customers[0][1];
        for (int i = 1; i < n; i++) {
            int fin = customers[i-1][0] + customers[i-1][1];
            if (customers[i][0] < fin) {
                sum += (fin - customers[i][0]);
                customers[i][0] = fin;
            }
            sum += customers[i][1];
        }
        return (double)sum / n;
    }
};
