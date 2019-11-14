#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define gc c = getchar()
inline int read() {
  int x = 0, f = 1;
  char gc;
  while (!isdigit(c)) gc;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 2005;
const int V = 305;
int n, m, v, e, a[N], b[N], g[V][V];
inline void Floyd() {
  for (int k = 1; k <= v; k++)
    for (int i = 1; i <= v; i++)
      for (int j = 1; j <= v; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
double p[N], f[N][N][2];
int main() {
  n = read(), m = read(), v = read(), e = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  for (int i = 1; i <= n; i++) scanf("%lf", p + i);
  memset(g, 0x3f, sizeof(g));
  for (int i = 1; i <= v; i++) g[i][i] = 0;
  while (e--) {
    int x = read(), y = read(), z = read();
    g[x][y] = min(g[x][y], z);
    g[y][x] = g[x][y];
  }
  Floyd();
  memset(f, 0x7f, sizeof(f));
  f[1][0][0] = f[1][1][1] = 0;
  for (int i = 2; i <= n; i++) {
    int a1 = a[i - 1], b1 = b[i - 1];
    int a2 = a[i], b2 = b[i];
    f[i][0][0] = f[i - 1][0][0] + g[a1][a2];
    for (int j = 1; j <= m && j <= i; j++) {
      f[i][j][0] = f[i - 1][j][0] + g[a1][a2];
      f[i][j][0] = min(f[i][j][0],
                       f[i - 1][j][1] +
                           p[i - 1] * g[b1][a2] +
                           (1 - p[i - 1]) * g[a1][a2]);
      f[i][j][1] = f[i - 1][j - 1][0] + p[i] * g[a1][b2] + (1 - p[i]) * g[a1][a2];
      f[i][j][1] = min(f[i][j][1],
                       f[i - 1][j - 1][1] +
                           p[i - 1] * p[i] * g[b1][b2] +
                           p[i - 1] * (1 - p[i]) * g[b1][a2] +
                           (1 - p[i - 1]) * p[i] * g[a1][b2] +
                           (1 - p[i - 1]) * (1 - p[i]) * g[a1][a2]);
    }
  }
  double ans = 1e300;
  for (int i = 0; i <= m; i++) ans = min(ans, min(f[n][i][0], f[n][i][1]));
  printf("%.2lf", ans);
}
