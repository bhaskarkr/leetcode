class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        l = max(sum(weights) // days, max(weights))
        r = sum(weights)
        def isValid(sums : int) -> bool:
            splits = 0
            curr = 0
            for pre in weights:
                if curr + pre > sums:
                    splits += 1
                    curr = 0
                curr += pre
            return splits <= days - 1
        while l < r:
            m = (l + r) // 2
            if isValid(m):
                r = m
            else:
                l = m + 1
        return l
