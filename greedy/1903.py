# https://leetcode.com/problems/largest-odd-number-in-string/

class Solution:
    def largestOddNumber(self, num: str) -> str:
	    n = len(num) - 1

	    while n >= 0:
		    if int(num[n]) % 2:
			    return num[:n + 1]
		    n -= 1

	    return ""
