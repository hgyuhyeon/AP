class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (auto i: asteroids) {
            int val = i;
            while (!s.empty() && (s.top() > 0 && i < 0)) {
                int a = s.top(), b = abs(i);
                if (a >= b) {
                    if (a == b) s.pop();
                    val = 0;
                    break;
                }
                s.pop();
            }
            if (val) s.push(val);
        }
        vector<int> ans(s.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};