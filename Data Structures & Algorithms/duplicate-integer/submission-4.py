class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        obj = defaultdict(int)
        
        for i in nums:
            if obj[i]:
                return True
            else:
                obj[i] = 1
        
        return False