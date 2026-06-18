class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        target = n / 3

        res = []
        hash_map = defaultdict(int)

        for item in nums:
            hash_map[item] += 1

        for item in hash_map.keys():
            if hash_map[item] > target:
                res.append(item)

        
        return res
