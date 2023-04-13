class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;

        for (auto i: pushed) {
            stk.push(i);
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        
        return stk.empty();
    }
};