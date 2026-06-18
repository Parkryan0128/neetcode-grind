class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for k in range(len(nums)-2):
            if k > 0 and nums[k] == nums[k - 1]:  # Skip duplicate values for 'k'
                continue
            i = k+1
            j = len(nums)-1
            while (i < j):
                if nums[k] + nums[i] + nums[j] > 0:
                    j -= 1
                elif nums[k] + nums[i] + nums[j] < 0:
                    i += 1
                else:
                    res.append([nums[i],nums[j],nums[k]])
                    while i < j and nums[i] == nums[i + 1]:
                        i += 1
                    while i < j and nums[j] == nums[j - 1]:
                        j -= 1

                    i += 1
                    j -= 1
        return res