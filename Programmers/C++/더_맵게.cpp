#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i < scoville.size(); i++)
        pq.push(scoville[i]);
    
    int first, second;
    while(!pq.empty() && pq.top() < K) {
        first = pq.top();
        pq.pop();
        if(pq.empty()) {
            answer = 0;
            break;
        }
        second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
        answer++;
    }
    if(answer == 0)
        return -1;
    return answer;
}