from ast import List
from collections import Counter


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        c = Counter(chars)
        for w in words:
            wc = Counter(w)
            if (c & wc == wc):
                ans += len(w)

        return ans
