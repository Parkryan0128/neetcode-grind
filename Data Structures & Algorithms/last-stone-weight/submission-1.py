class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-x for x in stones]
        maxHeap = stones
        heapq.heapify(maxHeap)

        while len(maxHeap) > 1:
            first = -1 * heapq.heappop(maxHeap)
            second = -1 * heapq.heappop(maxHeap)
            res = first - second
            if res > 0:
                heapq.heappush(maxHeap, -1 * res)
        
        if len(maxHeap) == 1:
            return -1 * heapq.heappop(maxHeap)
        else:
            return 0

