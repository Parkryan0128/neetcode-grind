class Solution:
    def jump(self, nums: List[int]) -> int:
        ans = 0
        l = r = 0
        target = len(nums) - 1

        while r < target:
            span = 0
            for i in range(l, r+1):
                span = max(span, nums[i]+i) 
            
            l = r + 1
            r = span
            ans += 1


        return ans

            
    