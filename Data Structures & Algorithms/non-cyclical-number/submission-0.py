class Solution:
    def isHappy(self, n: int) -> bool:
        empty_set = set()
        ans = n

        while ans != 1:
            total = 0
            while ans > 0:
                num = ans % 10
                total += num * num
                ans = ans // 10
            ans = total
            if total in empty_set:
                return False
            empty_set.add(total)
        
        return True


                
