class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long lo = 0, hi = 100000;
        while (lo < hi) {
            long long mid = (lo+hi)/2, sum = 0, pd = 4;
            long long i = 1, j = mid*2;
            for (; i < j; i++, j--, pd+=4) sum += (i * pd) + (j * pd);
            if (sum < neededApples) lo = mid + 1;
            else hi = mid;
        }
        return lo * 8;
    }
};