class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size(), 0);
        stack<int> s;
        int tempIndex = temp.size()-1;
        s.push(temp.size()-1);
        for (int i = temp.size() - 2; i >= 0; i--) {
            if (temp[i] < temp[i+1]) ans[i] = 1;
            else if (temp[i] < temp[s.top()]) ans[i] = s.top() - i;
            else if (temp[i] >= temp[s.top()]) {
                while (!s.empty()) {
                    if (temp[i] < temp[s.top()]) {
                        ans[i] = s.top() - i;
                        break;
                    }
                    s.pop();
                }
            }
            s.push(i);
        }
        return ans;
    }
};