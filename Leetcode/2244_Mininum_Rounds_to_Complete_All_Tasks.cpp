class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        int num = tasks[0], cnt = 1, res = 0;
        for (int i = 1; i < tasks.size(); i++) {
            if (tasks[i] != num) {
                if (cnt <= 1) {
                    if (i <= 1) return -1;
                    else if (tasks[i - 2] != tasks[i - 1]) return -1;
                }
                res++;
                cnt = 1;
                num = tasks[i];
            }
            else if (cnt == 3) {
                res++;
                cnt = 1;
            }
            else cnt++;
        }

        if (cnt > 1) return res + 1;
        else if (tasks.size() > 1 && tasks[tasks.size()-1] == tasks[tasks.size()-2]) return res + 1;
        else return -1;
    }
};