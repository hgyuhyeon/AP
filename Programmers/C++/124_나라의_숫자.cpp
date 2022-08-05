#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n) {
    string answer = "";
    stack<string> s;
    while(n>0) {
        switch(n % 3) {
            case 0:
                s.push("4");
                n = n / 3 - 1;
                break;
            case 1:
                s.push("1");
                n /= 3;
                break;
            case 2:
                s.push("2");
                n /= 3;
                break;
            default:
                break;
        }
        
    }
    
    while(!s.empty()) {
        answer += s.top();
        s.pop();
    }
    return answer;
}