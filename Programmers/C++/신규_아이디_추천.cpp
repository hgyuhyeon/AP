#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //1, 2
    for(int i=0;i<new_id.length();i++) {
        new_id[i] = tolower(new_id[i]); //1
        if((new_id[i]>='a'&&new_id[i]<='z')||(new_id[i]>='0'&&new_id[i]<='9')||new_id[i]=='-'||new_id[i]=='_'||new_id[i]=='.') { //2
            answer+=new_id[i];
        }
    }
    //3
    for(int i=1;i<answer.length();i++) {
        if(i!=0 && answer[i]=='.' && answer[i-1]=='.') {
            answer = answer.substr(0, i) + answer.substr(i+1, answer.size()-1);
            i--;}
    }
    //4
    if(!answer.empty()) { 
        if(answer[0]=='.')
            answer = answer.substr(1);
        if(answer[answer.size()-1]=='.')
            answer = answer.substr(0, answer.size()-1);
    }
    //5
    if(answer=="")
        answer += 'a';
    //6
    if(answer.size()>=16)
        answer.erase(answer.begin()+15, answer.end());
    if(answer[answer.size()-1]=='.')
        answer.erase(answer.size()-1);
    //7
    if(answer.size()<=2)
        while(answer.size()!=3) answer += answer[answer.size()-1];
    return answer;
}