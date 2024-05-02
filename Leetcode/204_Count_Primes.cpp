class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<int> v(n, 0);
        for (int i = 2; i < n; i++) {
            if (v[i]) continue;
            for (int j = 2*i; j < n; j += i) v[j] = 1;
        }
        return n - accumulate(v.begin(), v.end(), 0) - 2;
    }
};