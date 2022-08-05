#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int desc(int i, int j) {
    return i > j;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int target = priorities[location];
    queue<int> print;
    
    for(int i = 0; i<priorities.size(); i++)
        print.push(priorities[i]);
    
    sort(priorities.begin(), priorities.end(), desc);
    priorities.erase(find(priorities.begin(), priorities.end(), target), priorities.end());

    while(!priorities.empty()) {
        if(print.front()==priorities[0]) {
            print.pop();
            priorities.erase(priorities.begin());
            answer++;
        } else {
            int temp = print.front();
            print.pop();
            print.push(temp);
        }
        location--;
        if(location<0)
            location = print.size()-1;
    }
    
    for(int i = 0; i<=location; i++) {
        if(print.front()==target)
            answer++;
        print.pop();
    }
        
    
    return answer;
}