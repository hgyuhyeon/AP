#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int solution(vector<int> arr) {
    int answer = arr[0], val;
    for(int i=1; i<arr.size(); i++) {
        val = gcd(answer, arr[i]);        
        answer = answer * arr[i] / val;
    }
    return answer;
}