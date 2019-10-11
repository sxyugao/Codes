#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 3005;
int nedge, head[N];
struct Edge {
  int to, w, nxt;
} edge[N << 1];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int n, m, siz[N], f[N][N];
void dfs(int x, int fa) {
  if (siz[x] == 1) return;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    dfs(y, x), siz[x] += siz[y];
    for (int j = siz[x]; j; j--)
      for (int k = 0; k <= j; k++)
        f[x][j] = max(f[x][j], f[x][j - k] + f[y][k] - edge[i].w);
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n - m; i++)
    for (int num = read(); num; num--) {
      int x = read(), y = read();
      add(i, x, y), add(x, i, y);
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      f[i][j] = -1e9;
  for (int i = n - m + 1; i <= n; i++) f[i][1] = read(), siz[i] = 1;
  dfs(1, 0);
  for (int i = m; i; i--)
    if (f[1][i] >= 0) return printf("%d", i), 0;
}
