#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge, weights;
    int w = 0;
    for(int i=0; !bridge.empty() || i<truck_weights.size(); answer++) {
        if(!bridge.empty() && answer - bridge.front() >= bridge_length) {
            w -= weights.front();
            weights.pop();
            bridge.pop();
        }
        if(i < truck_weights.size() && w + truck_weights[i] <= weight) {
            bridge.push(answer);
            weights.push(truck_weights[i]);
            w += truck_weights[i];
            i++;
        }
    }
    return answer;
}