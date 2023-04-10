class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c: s) {
            switch(c) {
                case '(':
                case '{':
                case '[':
                    stk.push(c);
                    break;
                case ')':
                    if (!stk.empty() && stk.top() == '(') stk.pop();
                    else return false;
                    break;
                case '}':
                    if (!stk.empty() && stk.top() == '{') stk.pop();
                    else return false;
                    break;
                case ']':
                    if (!stk.empty() && stk.top() == '[') stk.pop();
                    else return false;
                    break;
                default:
                    return false;
            }
        }
        if (!stk.empty()) return false;
        else return true;
    }
};