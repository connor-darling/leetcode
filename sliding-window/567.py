# https://leetcode.com/problems/permutation-in-string/

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freq = defaultdict(int)
        window_freq = defaultdict(int)

        for c in s1:
            freq[c] += 1

        l = 0

        for r in range(len(s2)):
            window_freq[s2[r]] += 1

            while (r - l + 1) > len(s1):
                window_freq[s2[l]] -= 1

                if window_freq[s2[l]] == 0:
                    del window_freq[s2[l]]

                l += 1

            if window_freq == freq:
                return True
        
        return False
