class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product = 1
        product_no_zero = 1
        zeros = 0

        for num in nums:
            product *= num
            if num == 0:
                zeros += 1
            else:
                product_no_zero *= num

        if zeros > 1:
            return [0] * len(nums)
        
        ans = []

        if zeros == 1:
            for num in nums:
                if num != 0:
                    ans.append(0)
                else:
                    ans.append(product_no_zero)    
                    
            return ans


        for num in nums:
            ans.append(product // num)

        return ans