class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0':
            return 0

        ans = [int(s[-1] != '0'), int(s[-1] != '0'), 1]
        for i in range(len(s)-2, -1, -1):
            if s[i] == '0': 
                ans[0] = 0
            elif int(s[i]+s[i+1]) <= 26:
                ans[0] += ans[2]
            
            ans[2] = ans[1]
            ans[1] = ans[0]
        
        return ans[0]