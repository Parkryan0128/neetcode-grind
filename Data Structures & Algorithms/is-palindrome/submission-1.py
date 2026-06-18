class Solution:
    def isPalindrome(self, s: str) -> bool:
        filtered = s.replace(" ", "").lower()
        j = len(filtered)-1
        i = 0


        while i < j:
            if filtered[i].isalnum() and filtered[j].isalnum():
                if filtered[i] != filtered[j]:
                    return False
                i += 1
                j -= 1
            elif not filtered[i].isalnum():
                i += 1
            elif not filtered[j].isalnum():
                j -= 1
        return True