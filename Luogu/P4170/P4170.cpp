#include <iostream>
using namespace std;
string s;
int f[55][55];
int dfs(int l, int r) {
  if (f[l][r]) return f[l][r];
  if (l == r) return f[l][r] = 1;
  if (s[l] == s[r])
    f[l][r] = min(dfs(l + 1, r), dfs(l, r - 1));
  else {
    f[l][r] = 1e9;
    for (int i = l; i < r; ++i)
      f[l][r] = min(f[l][r], dfs(l, i) + dfs(i + 1, r));
  }
  return f[l][r];
}
int main() {
  cin >> s;
  cout << dfs(0, s.size() - 1) << endl;
}
