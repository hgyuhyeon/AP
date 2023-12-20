class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        cnt = 0
        for c in range(len(s)-1, -1, -1):
            if cnt != 0 and s[c] == ' ':
                break
            elif s[c] == ' ':
                continue
            else:
                cnt += 1
        return cnt