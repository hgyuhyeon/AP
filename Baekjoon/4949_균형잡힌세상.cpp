#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    
    while(1) {
        getline(cin, str);

        if (str == ".")
            break;
        
        stack<char> s;
        
        for (auto i: str) {
            if (i == '[' || i == '(')
                s.push(i);
            else if (i == ']' || i == ')') {
                if (s.empty()) {
                    s.push('e');
                    break;
                }
                else {
                    if ((s.top() == '[' && i == ']') || 
                    (s.top() == '(' && i == ')'))
                        s.pop();
                    else
                        break;
                }
            }
        }
        
        if (s.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    
    return 0;
}