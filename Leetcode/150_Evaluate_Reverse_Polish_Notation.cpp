class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int val2 = s.top();
                s.pop();
                int val = s.top();
                s.pop();

                if (c == "+") s.push(val + val2);
                else if (c == "-") s.push(val - val2);
                else if (c == "/") s.push(val / val2);
                else s.push(val * val2);
            }
            else {
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};