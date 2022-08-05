#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> n;
    for(int i=0; i<clothes.size(); i++) {
        if(n.find(clothes[i][1]) != n.end())
            n[clothes[i][1]]++;
        else
            n.insert(pair<string, int>(clothes[i][1], 1));
    }
    
    for(map<string, int>::iterator j=n.begin(); j!=n.end(); j++) {
        answer *= (j->second+1);
    }
    return answer-1;
}