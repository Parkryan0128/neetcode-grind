class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        countA = {}
        countB = {}

        for c in s:
            countA[c] = 1 + countA.get(c,0)

        for c in t:
            countB[c] = 1 + countB.get(c,0)

        return countA == countB