# https://leetcode.com/problems/two-sum/

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        my_map = defaultdict(int)

        """
        grab the complement meaning 
        comp = target - cur

        if that number is in out map, then we just return 
        indicies of comp and cur
        """

        for i in range(len(nums)):
            comp = target - nums[i]
            
            if comp in my_map:
                return [i, my_map[comp]]

            my_map[nums[i]] = i
        
        return []

