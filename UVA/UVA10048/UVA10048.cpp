#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 105;
const int INF = 0x3f3f3f3f;
int n, m, q, x, y, z;
int f[N][N];
int main() {
  for (int T = 1; ~scanf("%d%d%d", &n, &m, &q) && (n || m || q); T++) {
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++) {
      scanf("%d%d%d", &x, &y, &z);
      f[x][y] = f[y][x] = z;
    }
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          f[i][j] = min(f[i][j], max(f[i][k], f[k][j]));
    if (T > 1) puts("");
    printf("Case #%d\n", T);
    while (q--) {
      scanf("%d%d", &x, &y);
      if (f[x][y] == INF) {
        puts("no path");
      } else {
        printf("%d\n", f[x][y]);
      }
    }
  }
}
