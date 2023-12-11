class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> m;
        int n = arr.size() / 4;
        for (auto i: arr) {
            if (++m[i] > n) return i;
        }
        return 0;
    }
};