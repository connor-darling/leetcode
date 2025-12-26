# https://leetcode.com/problems/contains-duplicate/

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        """
        Given an integer array `nums`, return `true` if any value appears at least twice
        in the array, and return `false` if every element is distinct.
        """ 
        count = defaultdict(int)

        for i in range(len(nums)):
            count[nums[i]] += 1

            if count[nums[i]] > 1:
                return True
                
        return False

