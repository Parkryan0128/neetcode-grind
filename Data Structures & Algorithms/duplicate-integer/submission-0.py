class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        numss = set()
        for i in nums:
            numss.add(i)
        return len(numss) != len(nums)