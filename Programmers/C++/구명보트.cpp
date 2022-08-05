#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<>());
    
    int i = 0, j=people.size()-1;
    while(i<=j) {
        if(i<j && people[i] <= limit / 2) {
            answer += (j-i+1)/2 + (j-i+1)%2;
            break;
        }
        
        if(people[i] + people[j] <= limit) j--;
        i++;
        answer++;
    }
        
    return answer;
}