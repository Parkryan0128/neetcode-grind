class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)

        if n == 1:
            return strs[0]
        
        if n == 0:
            return ""

        
        pref = strs[0]

        for i in range(1, n):
            temp = ''
            for j in range(min(len(pref), len(strs[i]))):
                if strs[i][j] == pref[j]:
                    temp += strs[i][j]
                else:
                    break
            
            pref = temp
        
        return pref
