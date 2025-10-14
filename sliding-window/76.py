# https://leetcode.com/problems/minimum-window-substring/

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        count = defaultdict(int)
        window = defaultdict(int)

        for c in range(len(t)):
            count[t[c]] += 1
        
        l = 0
        res_len = float("inf")
        res_start = 0
        for r in range(len(s)):
            window[s[r]] += 1

            while self.dictsEq(window, count):
                if r - l + 1 < res_len:
                    res_len = r - l + 1
                    res_start = l
                
                window[s[l]] -= 1
                l += 1
            
        if (res_len == float('inf')):
            return ""

        return s[res_start:res_start + res_len]
    
    def dictsEq(self, dict1, count) -> bool:
        for char, freq in count.items():
            if dict1[char] < freq:
                return False
        return True
