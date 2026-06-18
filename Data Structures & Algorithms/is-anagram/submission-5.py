class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        obj1 = defaultdict(int)
        obj2 = defaultdict(int)

        for char in s:
            obj1[char] += 1

        for char in t:
            obj2[char] += 1

        
        for char in t:
            if obj1[char] != obj2[char]:
                return False

        return True