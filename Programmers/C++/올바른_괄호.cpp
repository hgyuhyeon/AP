#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    if(s.front() == ')' || s.back() == '(')
        return false;
    
    int count = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(' )
            count++;
        else if(s[i] == ')' && count > 0 )
            count--;
    }
    
    if(count)
        return false;

    return answer;
}