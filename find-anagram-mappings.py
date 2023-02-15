class Solution:
    def anagramMappings(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mapper = {}
        for idx, num in enumerate(nums2):
            mapper[num] = idx
        for idx, num in enumerate(nums1):
            nums1[idx] = mapper[num]
        return nums1
