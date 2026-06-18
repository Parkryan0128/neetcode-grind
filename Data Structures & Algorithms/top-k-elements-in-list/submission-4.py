class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if k == len(nums):
            return nums
        count = defaultdict(int)
        ans = []

        for num in nums:
            count[num] += 1
        
        freq = []

        for i in range(len(nums)+1):
            freq.append([])

        
        for num, cnt in count.items():
            freq[cnt].append(num)

        for i in reversed(range(len(freq))):
            for j in range(len(freq[i])):
                ans.append(freq[i][j])
                if k == len(ans):
                    return ans