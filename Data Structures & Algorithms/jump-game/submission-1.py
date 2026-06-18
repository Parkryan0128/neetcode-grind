class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n > 1 and nums[0] == 0:
            return False
    
        target_index = n - 1
        i = n - 2

        for i in reversed(range(n-1)):
            if nums[i] >= target_index - i:
                target_index = i



        return target_index == 0