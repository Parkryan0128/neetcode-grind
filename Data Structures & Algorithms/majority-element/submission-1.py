class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        hash_map = defaultdict(int)
        max_val = 0
        for item in nums:
            hash_map[item] += 1
            max_val = max(max_val, hash_map[item])

        for key in hash_map.keys():
            if hash_map[key] == max_val:
                return key
        

  