#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());
    
    for(int i=0; i<citations.size(); i++) {
        if(i+1 == citations[i]) {
            answer = i+1;
            break;
        }
        if(i+1 > citations[i]) {
            answer = i;
            break;
        }
    }
    
    if(citations.size() < citations[citations.size()-1])
        answer = citations.size();
    
    return answer;
}