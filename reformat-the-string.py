class Solution:
    def reformat(self, s: str) -> str:
        nums = []
        alphas = []
        for c in s:
            if c >= '0' and c <= '9':
                nums.append(c)
            else:
                alphas.append(c)
        ans = ""
        if abs(len(alphas)  - len(nums)) > 1:
            return ans
        if len(alphas) < len(nums):
            alphas, nums = nums, alphas
        # print(alphas, nums)
        for i in range(len(nums)):
            ans += alphas[i] + nums[i]
        if len(alphas) > len(nums):
            ans += alphas[-1]
        return ans
