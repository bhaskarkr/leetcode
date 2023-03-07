class Solution:
    def romanToInt(self, s: str) -> int:
        kv = {'I': 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D' : 500, 'M' : 1000}
        ans = kv[s[-1]]
        for i in range(len(s) - 2, -1, -1):
            print(kv[s[i]], ans)
            if kv[s[i]] < kv[s[i+1]]:
                ans -= kv[s[i]]
            else:
                ans += kv[s[i]]
        return ans
