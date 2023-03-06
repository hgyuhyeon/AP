class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr.size() == arr[arr.size()-1]) return arr.size() + k;
        
        int n = 1;
        for (int idx = 0; idx < arr.size(); n++) {
            if (arr[idx] == n) ++idx;
            else --k;

            if (k == 0) return n;
        }
        return n - 1 + k;
    }
};