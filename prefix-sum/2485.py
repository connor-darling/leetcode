# https://leetcode.com/problems/find-the-pivot-integer/

class Solution:
    def pivotInteger(self, n: int) -> int:
        r = 0
        for i in range(n + 1):
            r += i

        l = 0
        for i in range(1, n + 1):
            l += i

            if r == l:
                return i
            
            r -= i
        
        return -1
