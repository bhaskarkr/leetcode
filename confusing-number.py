class Solution:
    def confusingNumber(self, n: int) -> bool:
        a = str(n)
        b = ""
        for c in a:
            if c in ['2', '3', '4', '5', '7']:
                return False
            elif c == '6':
                c = '9'
            elif c == '9':
                c = '6'
            b += c
        return a[::-1] != b
