class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        i = 0
        j = n - 1

        while i <= j:
            mid = (i + j) // 2
            if nums[mid] == target:
                return mid

            if nums[i] == target:
                return i
            
            if nums[j] == target:
                return j


            if target < nums[mid] and target > nums[i] and nums[mid] > nums[i]:
                j = mid - 1
            elif target < nums[mid] and target < nums[i] and nums[mid] < nums[i]:
                j = mid - 1
            else:
                i = mid + 1


        return -1