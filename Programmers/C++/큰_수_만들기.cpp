#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer="";
    for(int i =0, index = -1;i<number.length()-k;i++){
        int var = 0;
        for(int j = index+1; j<=i+k;j++){
            if(number[j] == 9) {
                index = j;
                var = 9;
                break;
            }
            if(var < number[j]) {
                index = j;
                var = number[j];
            }
        }
        answer += var;
    }
    return answer;
}