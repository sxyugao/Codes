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
const int N = 5005;
const int P = 1e9 + 7;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
inline void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
inline void Add(int &x, int y) {
  x = x + y >= P ? x + y - P : x + y;
}
inline int Dec(int x, int y) {
  x -= y;
  if (x < 0) x += P;
  return x;
}
int n, m, f[N][N];
void dfs(int x, int fa) {
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    dfs(y, x);
    int sum = 0;
    for (int c = 1; c <= m; c++)
      if (f[y][c]) Add(sum, f[y][c]);
    for (int c = 1; c <= m; c++)
      if (f[x][c]) f[x][c] = 1LL * f[x][c] * Dec(sum, f[y][c]) % P;
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++)
    for (int num = read(); num; num--) f[i][read()] = 1;
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  int ans = 0;
  for (int c = 1; c <= m; c++) Add(ans, f[1][c]);
  printf("%d", ans);
}
