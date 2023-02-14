class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        i = len(a) - 1
        j = len(b) - 1
        ans = ""
        while i >= 0 or j >= 0 or carry > 0:
            if i >= 0:
                carry += int(a[i])
            if j >= 0:
                carry += int(b[j])
            ans = str(carry%2) + ans
            carry = carry // 2
            i -= 1
            j -= 1
        return ans
