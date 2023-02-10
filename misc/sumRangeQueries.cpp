/* #include "main.h" */

void print(std::vector<int> a) {
  for (const int num : a) {
    std::cout << num << " ";
  }
}

std::vector<int> updateRangeQueries(std::vector<int> &a, 
      std::vector<std::vector<int>> &q, int &val) {
  // Create Difference Array
  std::vector<int> d(a);
  for (int i = 1; i < a.size(); ++i) {
    d[i] = a[i] - a[i-1];
  }

  // Range Sum Queries the Difference Array
  for (int i = 0; i < q.size(); ++i) {
    int l = q[i][0];
    int r = q[i][1];
    d[l] += val;
    if (r < d.size()) d[r+1] -= val;
  }

  // Prefix Sum Difference Array
  for (int i = 1; i < d.size(); ++i) {
    d[i] += d[i-1];
  }

  return d;
}


int main() {
  std::vector<int> a = {3, 1, -2, 5, 4, 10};
  std::vector<int> ans;
  std::vector<std::vector<int>> queries = { {0,4}, {1,2}, {3, 5}, {0, 3} };
  int val = 1;

  ans = updateRangeQueries(a, queries, val);

  // Correct Output: [5, 4, 1, 8, 7, 11]
  print(ans);
  return 0;
}
