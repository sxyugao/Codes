class Solution {
 public:
  int uniquePaths(int m, int n) {
    long long ans = 1;
    for (int i = n, j = 1; j < m; ++i, ++j) {
      ans = ans * i / j;
    }
    return ans;
  }
};