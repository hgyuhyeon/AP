class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> m;
        for (auto s: arr) m[s]++;
        for (auto s: arr) {
            if (m[s] == 1) {
                if (--k == 0) return s;
            }
        }
        return "";
    }
};
