#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
int n, m;
LL k, a[25][25];
map<LL, int> f[25];
void dfs1(int x, int y, LL v) {
  if (x > n || y > m) return;
  if (x + y == (n + m) / 2 + 1) return (void)f[x][v ^ a[x][y]]++;
  dfs1(x + 1, y, v ^ a[x][y]);
  dfs1(x, y + 1, v ^ a[x][y]);
}
LL dfs2(int x, int y, LL v) {
  if (x < 1 || y < 1) return 0;
  if (x + y == (n + m) / 2 + 1) return f[x][v];
  return dfs2(x - 1, y, v ^ a[x][y]) + dfs2(x, y - 1, v ^ a[x][y]);
}
int main() {
  scanf("%d%d%lld", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%lld", &a[i][j]);
  dfs1(1, 1, k);
  printf("%lld", dfs2(n, m, 0));
}
