class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        max_heap = [-s for s in stones]
        heapq.heapify(max_heap)
        print(max_heap)
        while len(max_heap) > 1:
            x = -heapq.heappop(max_heap)
            y = -heapq.heappop(max_heap)

            if abs(x-y) > 0:
                heapq.heappush(max_heap, -(abs(x-y)))
        
        if len(max_heap) == 1:
            return -heapq.heappop(max_heap)
        return 0