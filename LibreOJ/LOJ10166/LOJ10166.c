#include <stdio.h>
#include <string.h>
int l, r, P;
int a[20], f[20][100][2];
int dfs(int len, int mod, int lim) {
  if (!len) return mod == 0;
  if (~f[len][mod][lim]) return f[len][mod][lim];
  int mx = lim ? a[len] : 9;
  int ans = 0;
  for (int i = 0; i <= mx; i++)
    ans += dfs(len - 1, (mod + i) % P, lim && i == mx);
  return f[len][mod][lim] = ans;
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
  while (~scanf("%d%d%d", &l, &r, &P)) printf("%d\n", solve(r) - solve(l - 1));
}