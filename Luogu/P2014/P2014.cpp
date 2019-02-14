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
int nedge, head[305];
struct Edge {
  int to, nxt;
} edge[1000];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int n, m, a[305], f[305][305];
void dfs(int x, int fa) {
  f[x][1] = a[x];
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    dfs(y, x);
    for (int j = m; j > 1; j--)
      for (int k = 1; k < j; k++) {
        f[x][j] = max(f[x][j], f[x][j - k] + f[y][k]);
      }
  }
}
int main() {
  n = read(), m = read() + 1;
  for (int i = 1; i <= n; i++) {
    int x = read();
    a[i] = read();
    add(i, x), add(x, i);
  }
  dfs(0, -1);
  printf("%d", f[0][m]);
}