#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> nums;
string temp;
bool n[7];

void findnum(int depth, string numbers) {
    
    for(int i = 0; i<numbers.size(); i++) {
        if(depth == -1)
            return;
        if(!n[i]) {
            n[i] = true;
            temp += numbers[i];
            nums.insert(stoi(temp));
            findnum(depth-1, numbers);
            n[i] = false;
            temp.pop_back();
            }
        }
}

int solution(string numbers) {
    int answer = 0;
    findnum(numbers.size(), numbers);
    
    for(auto i : nums) {
        if(i==1||i==0)
            continue;
        
        int j = 2;
        for(; j <= i / 2 ; j++){
            if(i % j == 0) break;
        }
        if(j > i/2)
            answer++;
    }
    return answer;
}