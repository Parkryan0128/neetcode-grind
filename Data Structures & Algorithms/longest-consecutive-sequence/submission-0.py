class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        max_sequence = 0

        for num in numSet:
            if (num-1) not in numSet:
                length = 1
                while num+length in numSet:
                    length += 1
                max_sequence = max(length, max_sequence)

        
        return max_sequence
