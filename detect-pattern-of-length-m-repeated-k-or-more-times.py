class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        for i in range(len(arr)-m+1):
            pattern = arr[i : i + m]
            if pattern * k == arr[i : i + m * k]:
                return True


        return False
