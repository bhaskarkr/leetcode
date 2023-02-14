class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        sum = 0
        for i in range(len(nums)//2):
            sum += int(str(nums[i])+str(nums[-1-i]))
        if len(nums) % 2 == 1:
            sum += nums[len(nums)//2]
        return sum
