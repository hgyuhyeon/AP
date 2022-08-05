#include <string>
#include <vector>

using namespace std;

int answer = 0, num = 0;

void dfs(vector<int> numbers, int target, int index) {
    if(index >= numbers.size()) {
        if(num == target)
            answer++;
        return;
    }
    num+=numbers[index];
    dfs(numbers, target, index+1);
    num-=(numbers[index]*2);
    dfs(numbers, target, index+1);
    num+=numbers[index];

}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0);
    return answer;
}