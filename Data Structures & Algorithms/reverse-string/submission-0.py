class Solution:
    def reverseString(self, s: List[str]) -> None:
        n = len(s)
        i = 0
        j = n - 1

        while i < j:
            temp = s[i]
            s[i] = s[j]
            s[j] = temp
            i += 1
            j -= 1
        