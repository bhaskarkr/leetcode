class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        i = len(num) - 1
        while i >= 0 or k > 0:
            k += (num[i] if i >= 0 else 0)
            if i >= 0:
                num[i] = k % 10
            else:
                num = [k % 10] + num
            k //= 10
            i -= 1
        return num 
