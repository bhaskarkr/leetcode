class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []
        for q in queries:
            for word in dictionary:
                diff = 0
                for c1, c2 in zip(q, word):
                    if c1 != c2:
                        diff += 1
                if diff <= 2:
                    ans.append(q)
                    break
        return ans
