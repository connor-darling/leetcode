class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    int a = 0;
    int b = 0;
    std::vector<std::string> res;
    string range;
    while (a < nums.size()) {
      b = a + 1;
      while (b < nums.size()) {
        if (nums[b - 1] + 1 != nums[b])
          break;
        ++b;
      }

      if (b - a == 1) {
        range = std::to_string(nums[a]);
      } else {
        range = std::to_string(nums[a]) + "->" + to_string(nums[b - 1]);
      }

      res.push_back(range);
      a = b;
    }

    return res;
  }
};
