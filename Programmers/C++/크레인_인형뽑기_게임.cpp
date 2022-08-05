#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket; //바구니 스택
    for(int i=0;i<moves.size();i++) {
        int mov = moves[i]-1;
        int res;
        for(int j=0;j<board.size();j++) 
            if(board[j][mov]!=0) {
                res = board[j][mov];
                board[j][mov]=0;
                basket.push_back(res);
                break;
            }        
        
        if(basket.size()>1 && basket[basket.size()-1] == basket[basket.size()-2]) {
            basket.pop_back();
            basket.pop_back();
            answer+=2;
        }
    }
    
    return answer;
}