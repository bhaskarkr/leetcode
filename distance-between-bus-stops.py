class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        for i in range(1, len(distance)):
            distance[i] += distance[i - 1]
        distance.insert(0, 0)
        if start > destination:
            start, destination = destination, start
        return min(distance[destination] - distance[start], distance[start] + distance[-1] - distance[destination])
