class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        l1 = set(nums1)
        l2 = set(nums2)
        ans = [[], []]
        for num in l1:
            if num not in l2:
                ans[0].append(num)
        for num in l2:
            if num not in l1:
                ans[-1].append(num)
        return ans
