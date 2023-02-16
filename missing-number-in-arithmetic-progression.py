class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        diff = (arr[-1] - arr[0]) // len(arr)
        l = 0
        r = len(arr) - 1
        while l < r:
            m = (l + r) // 2
            if arr[m] == arr[0] + diff*m:
                l = m + 1
            else:
                r = m
        return arr[0] + l * diff
