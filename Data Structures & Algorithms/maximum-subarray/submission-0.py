class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        sum_max = nums[0]
        subsum = 0

        for i in range(len(nums)):
            subsum = subsum + nums[i]
            sum_max = max(sum_max, subsum)
            
            if subsum < 0:
                subsum = 0
                    
        return sum_max