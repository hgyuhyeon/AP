class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1e9, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;

            int hrs = 0;
            for (auto p: piles) {
                hrs += (p / mid);
                if (p % mid > 0) hrs++;
            }
            
            if (hrs <= h) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};