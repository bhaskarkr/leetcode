class Solution:
    def similarPairs(self, words: List[str]) -> int:
        bucket = {}
        for word in words:
            l = tuple(sorted(set(word)))
            if l not in bucket:
                bucket[l] = 0
            bucket[l] += 1
        ans = 0
        for k,v in bucket.items():
            ans += (v * (v - 1)) // 2
        return ans
