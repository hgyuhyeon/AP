class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int lo = 1, hi = 1e14, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;

            long long int total = 0;
            for (auto t: time) total += (mid / t);
            // mid 기간만큼 운행 가능한 버스 운행 횟수(= 1 trip)를 추가

            if (total >= totalTrips) hi = mid; // 남으면 줄이고
            else lo = mid + 1; // 모자라면 늘림
        }
        return lo;
    }
};