class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        ans = []
        for i in range(0, len(s), k):
            temp = s[i : i + k]
            ans.append(temp + fill*(k - len(temp)))
        return ans
