class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i = 1, cnt = 0; i <= n; i++) {
            if (n % i == 0) cnt++;
            if (cnt == k) return i;
        }
        return -1;
    }
};
