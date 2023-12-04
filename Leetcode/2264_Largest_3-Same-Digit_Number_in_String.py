class Solution:
    def largestGoodInteger(self, num: str) -> str:
        ans = ""
        for i in range(0, len(num)-2, 1):
            if (num[i] == num[i+1]) & (num[i+1] == num[i+2]):
                ans = max(num[i]*3, ans)
        return ans