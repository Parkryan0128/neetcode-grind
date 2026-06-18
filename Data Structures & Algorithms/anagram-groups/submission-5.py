class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        obj = defaultdict(list)

        for item in strs:
            arr = [0] * 26
            for char in item:
                arr[ord(char) - ord('a')] += 1

            obj[tuple(arr)].append(item)
        
        return list(obj.values())

        