class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        obj = defaultdict(list)
        res = []

        print(ord("a")-97)
        for item in strs:
            count = [0] * 26
            for char in item:
                count[ord(char)-97] += 1
            obj[tuple(count)].append(item)

        return list(obj.values())