class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        m = dict()
        c = len(nums) / 2
        for n in nums:
            if n not in m:
                m[n] = 1
            else:
                m[n] += 1
            if m[n] > c:
                return n
        return nums[0]