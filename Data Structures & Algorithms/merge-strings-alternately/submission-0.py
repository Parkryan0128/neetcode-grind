class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        min_len = min(len(word1), len(word2))
        max_len = max(len(word1), len(word2))
        res = ""
        i = 0
        while i < min_len:
            res += word1[i]
            res += word2[i]
            i += 1

        while i < len(word1):
            res += word1[i]
            i += 1
        while i < len(word2):
            res += word2[i]
            i += 1
            
        return res