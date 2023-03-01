class Solution:
    def merger(self, left : List[int], right : List[int]) -> List[int]:
        if len(left) == 0:
            return right
        elif len(right) == 0:
            return left
        result = []
        i = 0
        j = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1
        while i < len(left):
            result.append(left[i])
            i += 1
        while j < len(right):
            result.append(right[j])
            j += 1
        return result

    def splitArr(self, nums : List[int], start : int, end : int) -> List[int]:
        if start == end:
            return [nums[start]]
        mid = (end + start) // 2
        left = self.splitArr(nums, start, mid)
        right = self.splitArr(nums, mid + 1, end)
        return self.merger(left, right)
    def sortArray(self, nums: List[int]) -> List[int]:
        return self.splitArr(nums, 0, len(nums) -1 )
