class Solution:
    def validPalindrome(self, s: str) -> bool:
        n = len(s)
        i = 0
        j = n - 1
        
        while i < j:
            if s[i] != s[j]:
                left = s[i + 1 : j + 1]
                right = s[i : j]

                return left == left[::-1] or right == right[::-1]
            i += 1
            j -= 1
        
        return True
