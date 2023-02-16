class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        ans = 0
        j = 0
        sum = 0
        for i in range(len(calories)):
            sum += calories[i]
            if i >= k - 1:
                if sum > upper:
                    ans += 1
                elif sum < lower:
                    ans -= 1
                sum -= calories[j]
                j += 1
            
        return ans
