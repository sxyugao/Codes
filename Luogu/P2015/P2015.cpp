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
const int N = 105;
int nedge, head[N];
struct Edge {
  int to, nxt, w;
} edge[N << 1];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int n, m, siz[N], f[N][N];
void dfs(int x, int fa) {
  siz[x] = 1;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    dfs(y, x), siz[x] += siz[y];
    for (int j = min(siz[x], m); j >= 1; j--)
      for (int k = 0; k < j && k <= siz[y]; k++)
        f[x][j] = max(f[x][j], f[x][j - k - 1] + f[y][k] + edge[i].w);
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read(), z = read();
    add(x, y, z), add(y, x, z);
  }
  dfs(1, 0);
  printf("%d", f[1][m]);
}
