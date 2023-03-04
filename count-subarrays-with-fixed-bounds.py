class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        minKIndex = -1
        maxKIndex = -1
        invalidIndex = -1
        ans = 0
        for i, num in enumerate(nums):
            if num < minK or num > maxK:
                invalidIndex = i
            if num == minK:
                minKIndex = i
            if num == maxK:
                maxKIndex = i
            ans += max(0, min(minKIndex, maxKIndex) - invalidIndex)
        return ans
