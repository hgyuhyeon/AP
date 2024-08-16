class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size(), ans = 0;
        pair<int, int> n1[n], n2[n];
        for (int i = 0; i < n; i++) {
            n1[i] = {arrays[i][0], i};
            n2[i] = {arrays[i].back(), i};
        }
        sort(n1, n1+n);
        sort(n2, n2+n);
        if (n2[n-1].second != n1[0].second) return n2[n-1].first - n1[0].first;
        return max(n2[n-2].first - n1[0].first, n2[n-1].first - n1[1].first);
    }
};
