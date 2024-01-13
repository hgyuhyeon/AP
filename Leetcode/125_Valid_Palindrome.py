class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = ''.join(filter(str.isalnum, s))
        for i in range(0, int(len(s)/2)):
            if s[i] != s[len(s)-1-i]:
                return False
        return True