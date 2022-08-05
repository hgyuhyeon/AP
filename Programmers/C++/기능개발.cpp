#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> process;
    for(int i=0; i<progresses.size();i++)
        process.push(progresses[i]);
    
    for(int i = 0, day = 0;!process.empty() || i<progresses.size(); day++) { 
        int count = 0;
        while(!process.empty() && process.front() + speeds[i] * day >= 100) {
            process.pop();
            i++;
            count++;
        }
        if(count != 0)
            answer.push_back(count);
    }
    return answer;
}