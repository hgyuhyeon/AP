class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0;
        int maxSalary = 0, minSalary = INT_MAX;
        for (auto i: salary) {
            ans += i;
            maxSalary = max(maxSalary, i);
            minSalary = min(minSalary, i);
        }

        ans -= (maxSalary + minSalary);
        return ans / (salary.size() - 2);
    }
};