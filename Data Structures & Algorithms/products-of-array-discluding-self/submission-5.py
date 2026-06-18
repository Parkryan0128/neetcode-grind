class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zeros = 0
        product = 1
        res = [0] * len(nums)
        
        for num in nums:
            if num == 0:
                zeros += 1
            else:
                product *= num
        
        if zeros > 1:
            return res
        
        if zeros == 1:
            for i in range(len(nums)):
                if nums[i] == 0:
                    res[i] = product
            return res

            
        for i in range(len(nums)):
            res[i] = int(product / nums[i])
        
        return res
        