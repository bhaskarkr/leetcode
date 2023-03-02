class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        j = 0
        chars[:] = list(chars)
        while i < len(chars):
            curr = chars[i]
            count = 0
            chars[j] = chars[i]
            while i < len(chars) and curr == chars[i]:
                count += 1
                i += 1
            j += 1
            if count != 1:
                for c in str(count):
                    chars[j] = c
                    j += 1
        return j
                
