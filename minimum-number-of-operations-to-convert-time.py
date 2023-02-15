class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        current = current.split(':')
        current = int(current[0]) * 60 + int(current[1])
        correct = correct.split(':')
        correct = int(correct[0]) * 60 + int(correct[1])
        diff = abs(correct - current)
        divs = [1, 5, 15, 60]
        i = 3
        ans = 0
        print(diff)
        while i >= 0 and diff > 0:
            if diff >= divs[i]:
                ans += diff // divs[i]
                diff %= divs[i]
            i -= 1
        return ans
