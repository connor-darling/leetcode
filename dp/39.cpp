class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    rec(candidates, {}, target, res, 0, 0);
    return res;
  }

  void rec(const vector<int> &candidates, vector<int> current, int t,
           vector<vector<int>> &res, int sum, int i) {
    if (sum > t)
      return;
    if (sum == t) {
      res.push_back(current);
      return;
    }

    for (int j = i; j < candidates.size(); ++j) {
      sum += candidates[j];
      current.push_back(candidates[j]);
      rec(candidates, current, t, res, sum, j);
      sum -= candidates[j];
      current.pop_back();
    }
  }
};
