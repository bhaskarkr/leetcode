class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def validate(limit : int) -> int:
            sum = 0
            for num in piles:
                sum += num // limit + (1 if num % limit > 0 else 0)
            return sum
        if len(piles) > h:
            return -1
        l = 1
        r = max(piles)
        ans = r
        while l < r:
            m = (l + r) // 2
            print(m)
            val = validate(m)
            if val > h:
                l = m + 1
            else:
                ans = min(m, ans)
                r = m
        return ans
        
