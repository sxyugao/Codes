#include <cstdio>
#include <iostream>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 20;
int head[N];
struct Edge {
  int to, nxt, w;
} edge[N * N];
int n, m, f[N][1 << N];
int dfs(int x, int s) {
  if (x == n) return 0;
  if (f[x][s] > 0) return f[x][s];
  int ans = -1 << 31;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (s & (1 << (y - 1))) continue;
    ans = max(ans, edge[i].w + dfs(y, s | 1 << (x - 1)));
  }
  return f[x][s] = ans;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read() + 1, y = read() + 1, z = read();
    edge[i].to = y;
    edge[i].w = z;
    edge[i].nxt = head[x];
    head[x] = i;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 1 << n; j++)
      f[i][j] = -1 << 31;
  printf("%d", dfs(1, 0));
}
