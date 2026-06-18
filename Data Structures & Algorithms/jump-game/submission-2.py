class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        target_index = n - 1

        for i in reversed(range(n-1)):
            if nums[i] >= target_index - i:
                target_index = i



        return target_index == 0