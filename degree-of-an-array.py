class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        start = {}
        count = {}
        ans = 10e9
        max_count = 0
        for i, ele in enumerate(nums):
            if ele not in start:
                start[ele] = i
                count[ele] = 0   
            count[ele] += 1
            if count[ele] >= max_count:
                if count[ele] == max_count:
                    ans = min(ans, i - start[ele] + 1)
                else:
                    ans = i - start[ele] + 1
                max_count = count[ele]
        return ans
