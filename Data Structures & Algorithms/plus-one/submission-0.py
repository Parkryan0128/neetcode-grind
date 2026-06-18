class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        ans = []
        if (digits[n-1] < 9):
            digits[n-1] = digits[n-1] + 1
        else:
            digits[n-1] = 10
            for i in range(n-1,-1,-1):
                if digits[i] == 10:
                    digits[i] = 0
                    if i == 0:
                        digits.insert(0,1)
                    else:
                        digits[i-1] += 1
                    


        return digits