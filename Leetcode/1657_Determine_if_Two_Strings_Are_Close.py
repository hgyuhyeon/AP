class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2): return False
        
        m1 = [0] * 26
        m2 = [0] * 26

        for i in range(0, len(word1)):
            m1[ord(word1[i]) - ord('a')] += 1
            m2[ord(word2[i]) - ord('a')] += 1
        
        for i in range(0, len(m1)):
            if m1[i] == 0 and m2[i] != 0 or m1[i] != 0 and m2[i] == 0: return False

        m1.sort()
        m2.sort()

        return m1 == m2