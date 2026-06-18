class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        freq = [[] for i in range(len(nums)+1)]

        for n in nums:
            count[n] = 1 + count.get(n,0)
        
        for key,item in count.items():
            freq[item].append(key)
        
        res = []
        for i in range(len(freq)-1,0,-1):
            for item in freq[i]:
                res.append(item)
                if len(res) == k:
                    return res

