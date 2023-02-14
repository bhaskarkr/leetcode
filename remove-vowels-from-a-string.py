class Solution:
    def removeVowels(self, s: str) -> str:
        return "".join(c if c not in ['a', 'e', 'i', 'o', 'u'] else '' for c in s)
