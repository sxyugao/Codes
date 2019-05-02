#include <stdio.h>
#include <string.h>
int l, r, a[10], f[10][10][2];
int dfs(int len, int lst, int lim) {
  if (!len) return 1;
  if (~f[len][lst][lim]) return f[len][lst][lim];
  int ans = 0;
  int mx = lim ? a[len] : 9;
  for (int i = 0; i <= mx; i++) {
    if (i == 4) continue;
    if (lst == 6 && i == 2) continue;
    ans += dfs(len - 1, i, lim && i == mx);
  }
  return f[len][lst][lim] = ans;
}
int solve(int x) {
  int len = 0;
  do {
    a[++len] = x % 10;
    x /= 10;
  } while (x);
  memset(f, -1, sizeof(f));
  return dfs(len, 0, 1);
}
int main() {
  while (scanf("%d%d", &l, &r), l || r) printf("%d\n", solve(r) - solve(l - 1));
}