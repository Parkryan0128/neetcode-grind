class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        obj = {}
        
        for num in nums:
            obj[num] = 1 + obj.get(num,0)


        heap = []

        for item in obj.keys():
            heapq.heappush(heap, (obj[item], item))   
            if len(heap) > k:
                heapq.heappop(heap)

        res = []

        for i in range(len(heap)):
            res.append(heapq.heappop(heap)[1])

        return res