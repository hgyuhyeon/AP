#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count = 0;
    for (int i = 0; i < prices.size(); i++) {
        answer.push_back(0);
        int j = 0;
        for (j = i + 1; j < prices.size(); j++) {
            if (prices[i] > prices[j]) { 
                answer[i] = j - i; 
                break;
            }
        }
        if (j == prices.size()) {
            answer[i] = j - 1 - i;
        }
    }
    return answer;
}