from ast import List


class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        x = set()
        for p in points:
            x.add(p[0])
        lx = list(x)
        lx.sort()
        ans = 0
        for i in range(0, len(lx)-1, 1):
            ans = max(ans, lx[i+1] - lx[i])
        return ans