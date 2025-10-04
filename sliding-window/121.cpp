// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) {
      return 0;
    }

    int max = 0;
    int l = 0;
    int r = 1;

    while (l < r && r < prices.size()) {
      if (prices[r] - prices[l] > max) {
        max = prices[r] - prices[l];
      }

      if (prices[r] < prices[l]) {
        l = r;
      }

      ++r;
    }

    return max;
  }
};
