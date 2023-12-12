from ast import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        idx1 = nums.index(max(nums))
        val1 = nums[idx1] - 1
        nums.remove(val1 + 1)
        val2 = max(nums) - 1
        return val1 * val2