class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int un = 0, tmp = 0, ans = 0, n = customers.size();
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i]) un += customers[i];
            else ans += customers[i];
        }
        tmp = un;
        for (int i = minutes; i < n; i++) {
            if (!grumpy[i]) ans += customers[i];
            else tmp += customers[i];
            if (grumpy[i-minutes]) tmp -= customers[i-minutes];
            un = max(un, tmp);
        }
        return ans + un;
    }
};