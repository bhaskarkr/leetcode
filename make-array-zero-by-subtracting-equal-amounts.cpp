class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        counts = Counter(nums)
        ans = len(counts.keys())
        return ans if counts.get(0, 0) == 0 else ans - 1 
