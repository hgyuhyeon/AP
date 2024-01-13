class Solution:
    def minSteps(self, s: str, t: str) -> int:
        m1 = {}
        m2 = {}
        ans = 0
        for c in range(ord('a'), ord('z')+1):
            m1[chr(c)] = 0
            m2[chr(c)] = 0

        for i in range(0, len(s)):
            m1[s[i]] += 1
            m2[t[i]] += 1

        for c in range(ord('a'), ord('z')+1):
            ans += abs(m1[chr(c)] - m2[chr(c)])

        return int(ans / 2)