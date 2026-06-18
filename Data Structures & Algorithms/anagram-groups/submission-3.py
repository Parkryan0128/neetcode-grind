class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)

        for s in strs:
            clist = [0] * 26
            for c in s:
                clist[ord(c) - ord('a')] += 1
            res[tuple(clist)].append(s)
        return list(res.values())