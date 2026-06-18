class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        items = defaultdict(int)
        max_count = 0

        n = len(s)
        i = 0

        while i < n:
            if items[s[i]]:
                i = items[s[i]] + 1
                items = defaultdict(int)
            items[s[i]] = i
            max_count = max(max_count, len(items.keys()))
            i += 1


        return max_count