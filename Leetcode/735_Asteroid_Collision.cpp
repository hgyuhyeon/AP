class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (auto a: asteroids) {
            if (s.empty()) s.push(a);
            else {
                if ((a > 0 && s.top() > 0) || (a < 0 && s.top() < 0)) {
                    s.push(a);
                }
                else { // collide
                    while (!s.empty() && s.top() > 0 && s.top() < abs(a)) s.pop();
                    if (!s.empty() && (s.top() == abs(a))) s.pop();
                    else if (!s.empty() && (s.top() > abs(a))) continue;
                    else s.push(a);
                }
            }
        }

        vector<int> ans(s.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};