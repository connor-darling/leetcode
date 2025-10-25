# https://leetcode.com/problems/strictly-palindromic-number

class Solution:
    def isStrictlyPalindromic(self, n: int) -> bool:
        d = deque()

        base = n - 2

        while n > 0:
            d.appendleft(n % base)
            n /= base
        
        for num in d:
            if num != d[-1]:
                return False
            
            d.pop()
            d.popleft()
        
        return True
