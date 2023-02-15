class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        counter = {}
        for word in words:
            for c in word:
                if c not in counter:
                    counter[c] = 0
                counter[c] += 1
        print(counter)
        for k, v in counter.items():
            if v % len(words) != 0:
                return False
        return True
