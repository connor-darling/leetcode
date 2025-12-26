# https://leetcode.com/problems/valid-anagram/

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        s_dict = defaultdict(int)

        for c in s:
            s_dict[c] += 1

        for c in t:
            if c not in s_dict:
                return False
            s_dict[c] -= 1

        for val in s_dict.values():
            if val != 0:
                return False
        
        return True

