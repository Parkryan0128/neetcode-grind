class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False  # Early exit if lengths are different

        obj1 = {}
        for i in s:
            obj1[i] = obj1.get(i, 0) + 1

        obj2 = {}
        for i in t:
            obj2[i] = obj2.get(i, 0) + 1

        return obj1 == obj2 



    