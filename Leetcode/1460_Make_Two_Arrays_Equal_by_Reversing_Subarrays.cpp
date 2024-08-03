class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j > i; j--) {
                if (target[i] == arr[j]) reverse(arr.begin()+i, arr.begin()+j+1);
            }
        }
        if (target == arr) return true;
        else return false;
    }
};
