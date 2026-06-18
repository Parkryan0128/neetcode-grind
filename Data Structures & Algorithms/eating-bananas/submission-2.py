class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        piles.sort()
        max_pile = piles[-1]
        i = 1
        
        res = max_pile

        while i <= max_pile:
            mid = (max_pile + i) // 2

            total = 0
            for p in piles:
                total += math.ceil(float(p) / mid)
            if total <= h:
                res = mid
                max_pile = mid - 1
            else:
                i = mid + 1
        
        return res

        