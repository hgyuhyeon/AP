class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int std1 = accumulate(students.begin(), students.end(), 0), std0 = students.size() - std1, n = sandwiches.size();
        for (int i = 0; i < n; i++) {
            if (sandwiches[i] == 0 && std0 > 0) std0--;
            else if (sandwiches[i] == 1 && std1 > 0) std1--;
            else return n - i;
        }
        return 0;
    }
};