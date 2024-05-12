class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1e9;
        while (lo < hi) {
            int mid = (lo+hi)/2, sum = 0;
            for (auto p: piles) sum += (p / mid + (p % mid != 0 ? 1 : 0));
            if (sum <= h) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};