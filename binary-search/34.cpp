class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int hi = nums.size() - 1;
      int lo = 0;

      if (lo == hi && nums[lo] == target) {
        return {lo, hi};
      }
      
      while (lo <= hi) {
        int mid = (hi + lo) / 2;
        if (nums[mid] == target) {
          int res1 = mid;
          int res2 = mid;
          for (int i = mid; i >= 0 && (nums[i] == target); --i) {
            res1 = i;
          }

          for (int i = mid; i < nums.size() && (nums[i] == target); ++i) {
            res2 = i;
          }

          return {res1, res2};
        }

        if (nums[mid] > target) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }

      return {-1, -1};
    }
};
