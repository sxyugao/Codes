#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[105];
int f[105][105];
int dfs(int l, int r) {
  if (f[l][r]) return f[l][r];
  if (l > r) return 0;
  if (l == r) return 1;
  int ans = (s[l] + 1 == s[r] || s[l] + 2 == s[r] ? 0 : 2) + dfs(l + 1, r - 1);
  for (int i = l; i < r; i++) ans = min(ans, dfs(l, i) + dfs(i + 1, r));
  return f[l][r] = ans;
}
int main() {
  gets(s + 1);
  printf("%d", dfs(1, strlen(s + 1)));
}
