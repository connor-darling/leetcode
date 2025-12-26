# https://leetcode.com/problems/group-anagrams/description/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = defaultdict(list)
        ans = []
        for s in strs:
            sorted_s = ''.join(sorted(s))
            groups[sorted_s].append(s)
        

        for k,v in groups.items():
            print(k,v)
            ans.append(v)
        
        return ans



