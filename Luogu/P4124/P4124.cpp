#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
int a[15];
LL f[15][2][2][2][2][10][10];
LL dfs(int len, bool lim, bool _4, bool _8, bool l, int x, int y) {
  if (!len) return l;
  if (~f[len][lim][_4][_8][l][x][y]) return f[len][lim][_4][_8][l][x][y];
  LL ans = 0;
  int mx = lim ? a[len] : 9;
  for (int i = len == 11; i <= mx; i++) {
    if (_4 && i == 8) continue;
    if (_8 && i == 4) continue;
    bool limit = lim && i == mx;
    bool __4 = _4 || i == 4;
    bool __8 = _8 || i == 8;
    ans += dfs(len - 1, limit, __4, __8, l || (i == x && i == y), y, i);
  }
  return f[len][lim][_4][_8][l][x][y] = ans;
}
LL solve(LL x) {
  if (x < 1e10) return 0;
  int len = 0;
  while (x) {
    a[++len] = x % 10;
    x /= 10;
  }
  memset(f, -1, sizeof(f));
  return dfs(len, 1, 0, 0, 0, 0, 0);
}
int main() {
  LL l, r;
  scanf("%lld%lld", &l, &r);
  printf("%lld\n", solve(r) - solve(l - 1));
}