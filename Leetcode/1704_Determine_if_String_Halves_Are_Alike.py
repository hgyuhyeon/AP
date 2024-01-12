class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        half = int(len(s) / 2)
        first = 0
        second = 0
        s = s.lower()
        for i in range(0, half):
            if s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] =='o' or s[i] =='u':
                first += 1
            if s[i+half] == 'a' or s[i+half] == 'e' or s[i+half] == 'i' or s[i+half] =='o' or s[i+half] =='u':
                second += 1

        if first == second: return True
        return False