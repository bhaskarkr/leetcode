class Solution:
    def countDigits(self, num: int) -> int:
        ans = 0
        counts = Counter(str(num))
        for k,v in Counter(str(num)).items():
            if int(k) != 0 and num % int(k) == 0:
                ans += v
        return ans
