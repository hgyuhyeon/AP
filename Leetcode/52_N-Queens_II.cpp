class Solution {
private:
    int ans = 0;
    int n;
    vector<int> v;
public:
    bool check(int lv) {
        for (int i = 0; i < lv; i++) {
            if (v[i] == v[lv] || (abs(v[lv] - v[i]) == lv - i)) return false;
        }
        return true;
    }
    void solve(int lv) {
        if (lv == n) ans++;
        else {
            for (int i = 0; i < n; i++) {
                v[lv] = i;
                if (check(lv)) solve(lv+1);
            }
        }
    }
    int totalNQueens(int n) {
        this->n = n;
        v = vector<int>(n);
        solve(0);
        return ans;
    }
};
