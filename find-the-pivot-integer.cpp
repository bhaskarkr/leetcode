class Solution:
    def pivotInteger(self, n: int) -> int:
        l = 1
        r = n
        total = (r * (r + 1)) // 2 
        while(l <= r):
            m = (l + r) // 2
            ls = (m * (m - 1)) // 2
            rs = total - (m * (m + 1)) // 2
            if ls == rs:
                return m
            elif ls < rs:
                l = m + 1
            else:
                r = m - 1
        return -1
