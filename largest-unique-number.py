class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        counts = Counter(nums)
        ans = -1
        for k,v in counts.items():
            if v == 1:
                ans = max(ans, k)
        return ans
