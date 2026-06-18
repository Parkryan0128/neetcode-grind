class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        lst = [0] * (n+1)
        lst[1] = 1
        lst[2] = 2

        for i in range(3,len(lst)):
            lst[i] = lst[i-1] + lst[i-2]


        
        return lst[n]
