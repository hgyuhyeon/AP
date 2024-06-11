class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for (auto i: arr1) m[i]++;
        int j = 0;
        for (int i = 0, n = arr2.size(); i < n; i++) {
            while (m[arr2[i]]--) arr1[j++] = arr2[i];
            m.erase(arr2[i]);
        }
        for (auto [i, v]: m) while (v--) arr1[j++] = i;
        return arr1;
    }
};