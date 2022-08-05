#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool first = true;
    for(int i =0; i<s.size(); i++) {
        if(s[i] == ' ') {
            first = true;
            answer += " ";
        }
        else if(first) {
            first = false;
            answer += toupper(s[i]);  
        }
        else
            answer += tolower(s[i]);
    }
    return answer;
}