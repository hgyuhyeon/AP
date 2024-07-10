class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, n * n));
        int lo = 0, hi = n - 1, num = 1;
        while (lo <= hi) {
            for (int i = lo; i < hi; i++) m[lo][i] = num++;
            for (int i = lo; i < hi; i++) m[i][hi] = num++;
            for (int i = hi; i > lo; i--) m[hi][i] = num++;
            for (int i = hi; i > lo; i--) m[i][lo] = num++;
            lo++; hi--;
        }
        return m;
    }
};
