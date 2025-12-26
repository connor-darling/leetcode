# https://leetcode.com/problems/group-anagrams/description/

"""
first approach, basically i am create a map that will hold arrays for each key

so lets say the things we are working with are:
strs = ["eat","tea","tan","ate","nat","bat"]

then we create a map where the key is the sorted value of s in strs
and the values are all the anagrams of that.

map = {
    'aet' : ['eat', 'tea', 'ate']
    'ant' : ['tan', 'nat']
    'abt' : ['bat']
}

then from here essentially just append each of the values in the map into
a 2d list/array and return that.

this approach is intuiative, but the problem is that the time and space complexity
is very bad

time complexity:  O(nmlogm) where m is the average len of str and we have to sort n times
space complexity: O(n + m) -> O(n) where n is the num of el's in groups and m is el's in ans
"""
# class Solution:
#     def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
#         groups = defaultdict(list)
#         ans = []
#         for s in strs:
#             sorted_s = ''.join(sorted(s))
#             groups[sorted_s].append(s)
#         
#
#         for k,v in groups.items():
#             print(k,v)
#             ans.append(v)
#         
#         return ans

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        """
        contraints tell us that each char is lowercase english letters a-z (26)

        count: the freq of characters in each str from a-z
        ex: 'eat' -> 1a, 1e, 1t

        count = [0] * 26 
        array of 26 zeros, one for each letter in the alphabet

        count[ord(c) - ord("a")]
        this will take the ascii value of c and and map it in the array
        """

        res = defaultdict(list)

        for s in strs:
            count = [0] * 26 

            for c in s:
                count[ord(c) - ord("a")] += 1

            res[tuple(count)].append(s)
        
        return list(res.values())

