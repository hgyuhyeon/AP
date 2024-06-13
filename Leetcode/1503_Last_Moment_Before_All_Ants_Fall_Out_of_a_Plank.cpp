class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if (!left.size() && !right.size()) return 0;
        sort(left.begin(), left.end(), greater<>());
        sort(right.begin(), right.end());
        if (!left.size()) return n - right[0];
        else if (!right.size()) return left[0] - 0;
        return max(left[0] - 0, n - right[0]);
    }
};