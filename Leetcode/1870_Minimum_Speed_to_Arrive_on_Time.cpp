class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if ((double)dist.size() - hour >= 1) return -1;
        int l = 1, r = 1e7, mid; 
        while (l < r) {
            mid = (l + r) / 2;
            double sum = 0;
            for (int i = 0; i < dist.size() - 1; i++) 
                sum += ceil((double)dist[i] / mid);
            sum += (double)dist.back() / mid;
            if (sum > hour) l = mid + 1;
            else r = mid;
        }

        return r;
    }
};