# https://leetcode.com/problems/top-k-frequent-elements/

"""
first approach is basically a sort everything, store in a map

get an array of the sorted values desc, then get a res array

for the first k eleemnts in the sort values desc array and grab

the keys then return that. not optimal at all but no horrible.

O(nlogn), priority queue is the optimal approach will try that next
"""

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mymap = defaultdict(int)

        for i in range(len(nums)):
            mymap[nums[i]] += 1

        sorted_items_desc = sorted(mymap.items(), key=lambda item: item[1], reverse=True)

        print(sorted_items_desc)

        res = [key for key, _ in sorted_items_desc[:k]]
        
        return res

        
