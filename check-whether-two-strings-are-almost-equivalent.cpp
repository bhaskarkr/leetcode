class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        dict1 = Counter(word1)
        dict2 = Counter(word2)
        all_keys = set(dict1.keys()).union(dict2.keys())
        ans = 0
        for c in all_keys:
            if abs(dict1.get(c, 0) - dict2.get(c, 0)) > 3:
                return False 
        return True
