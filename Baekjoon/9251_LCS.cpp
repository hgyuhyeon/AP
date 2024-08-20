#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

    int ans = 0;
    
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            dp[i][j] = dp[i-1][j-1] + (s1[i-1] == s2[j-1] ? 1 : 0);
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[s1.size()][s2.size()];

    return 0;
}



/*
  b c a
a 0 0 1
b 1 1 1
c 1 2 2

sss
sssss
  s s s s s
s 1 1 1 1 1 
s 1 2 2 2 2 
s 1 2 3 3 3 

ACAA
AAACBA
  A A A C B A
A 1 1 1 1 1 1
C 1 1 1 2 2 2
A 1 2 2 2 2 3
A 1 2 2 2 2 3

// 3이 나와야 하는데 4 나옴
3


ababa
babab
  b a b a b
a 0 1 1 1 1 
b 1 1 2 2 2 
a 1 2 2 3 3 
b 1 2 3 3 3 
a 1 2 3 4 4 

  b a b a b
a 0 1 1 1 1 
b 1 1 2 1 2 
a 1 2 2 2 2 
b 1 2 3 2 3 
a 1 2 3 3 3 
3


*/