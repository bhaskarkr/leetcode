class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            ans = [*ans, *[int(i) for i in str(num)]]
        return ans
