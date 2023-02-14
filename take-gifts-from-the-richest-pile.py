class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        gifts = [-gift for gift in gifts]
        heapify(gifts)
        while k:
            k -= 1
            top = math.isqrt(-heappop(gifts))
            heappush(gifts, -top)
        return -sum(gifts)



# from queue import PriorityQueue
# class Solution:
#     def pickGifts(self, gifts: List[int], k: int) -> int:
#         PQ = PriorityQueue()
#         for num in gifts:
#             PQ.put(-num)
#         while k > 0:
#             k -= 1
#             top = -PQ.get()
#             PQ.put(-math.isqrt(top))
#         ans = 0
#         while not PQ.empty():
#             ans += -PQ.get()
#         return ans
