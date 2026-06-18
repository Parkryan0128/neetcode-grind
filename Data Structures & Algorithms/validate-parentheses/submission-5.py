class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        obj = {
            "{":"}",
            "[":"]",
            "(":")"
        }
        for c in s:
            if c in obj.keys():
                stack.append(c)
            else:
                if len(stack) == 0:
                    return False
                last = stack.pop()
                if obj[last] != c:
                    return False

        if len(stack) > 0:
            return False
        
        return True