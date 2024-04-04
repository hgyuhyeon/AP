class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, size = 0;
        for (auto c: s) {
            if (c == '(') size++;
            else if (c == ')') size--;
            ans = max(ans, size);
        }
        return ans;
    }
};