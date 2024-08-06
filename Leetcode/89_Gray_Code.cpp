class Solution {
private:
    int n;
    vector<int> ans;
    vector<bool> v;
    void solve(bitset<32>& bs, int idx) {
        ans.push_back((int)bs.to_ulong());
        if (idx == n) return;
        for (int i = 0; i < n; i++) {
            bs[i] = !bs[i];
            if (!v[(int)bs.to_ulong()]) {
                v[(int)bs.to_ulong()] = true;
                solve(bs, i);
            }
            bs[i] = !bs[i];
        }
    }
public:
    vector<int> grayCode(int n) {
        this->n = n;
        v = vector<bool>(pow(2, n), false);
        v[0] = true;
        bitset<32> bs;
        solve(bs, 0);
        return ans;
    }
};
