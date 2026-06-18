class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        hash_map = defaultdict(int)
        n = len(s1)

        for item in s1:
            hash_map[item] += 1

        if len(s2) < n:
            return False

        left = 0
        right = n - 1

        while right < len(s2):
            copy = hash_map.copy()
            while copy[left] > 0:
                print("moved window")
                left += 1
                right += 1

            correct = 0
            for item in range(left, right+1):
                if copy[s2[item]] > 0:
                    correct += 1
                    copy[s2[item]] -= 1
                else:
                    break
            if correct == n:
                return True
            left += 1
            right += 1

        return False

