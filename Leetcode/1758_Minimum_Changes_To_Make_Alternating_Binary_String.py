class Solution:
    def minOperations(self, s: str) -> int:
        odd0 = 0
        even0 = 0
        odd1 = 0
        even1 = 0
        for i in range(0, len(s), 1):
            if s[i] == '0' and (i + 1) % 2 == 1:
                odd0 += 1
            elif s[i] == '0' and (i + 1) % 2 == 0:
                even0 += 1
            elif s[i] == '1' and (i + 1) % 2 == 1:
                odd1 += 1
            elif s[i] == '1' and (i + 1) % 2 == 0:
                even1 += 1
        
        if odd0 + even1 > odd1 + even0:
            return len(s) - (odd0 + even1)
        else:
            return len(s) - (odd1 + even0)

