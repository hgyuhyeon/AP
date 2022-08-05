#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown * yellow;
    vector<int> factors;
    for(int i=1; i <= yellow; i++) {
        if(yellow % i == 0)
            factors.push_back(i);
    }
    
    for(int i=0; i<factors.size(); i++) {
        int temp = 0;
        temp = yellow / factors[i];
        if((temp + factors[i]) * 2 + 4 == brown) {
            answer.push_back((temp > factors[i]) ? temp + 2 : factors[i] + 2);
            answer.push_back((temp < factors[i]) ? temp + 2 : factors[i] + 2);
            break;
        }
    }
    
    return answer;
}