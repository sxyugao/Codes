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
const int N = 2e5 + 5;
struct Graph {
  int nedge, head[N];
  struct Edge {
    int to, nxt;
  } edge[N << 1];
  void add(int x, int y) {
    edge[++nedge].to = y;
    edge[nedge].nxt = head[x];
    head[x] = nedge;
  }
} g1, g2;
int tot, a[N], col[N];
void dfs(int x) {
  col[x] = tot;
  for (int i = g1.head[x]; i; i = g1.edge[i].nxt) {
    int y = g1.edge[i].to;
    if (col[y] || a[y] ^ a[x]) continue;
    dfs(y);
  }
}
int d[N];
void dfs(int x, int fa) {
  d[x] = d[fa] + 1;
  for (int i = g2.head[x]; i; i = g2.edge[i].nxt) {
    int y = g2.edge[i].to;
    if (y == fa) continue;
    dfs(y, x);
  }
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    g1.add(x, y), g1.add(y, x);
  }
  for (int i = 1; i <= n; i++)
    if (!col[i]) tot++, dfs(i);
  for (int x = 1; x <= n; x++)
    for (int i = g1.head[x]; i; i = g1.edge[i].nxt) {
      int y = g1.edge[i].to;
      if (col[x] ^ col[y]) g2.add(col[x], col[y]);
    }
  dfs(1, 0);
  int p = 0;
  for (int i = 1; i <= tot; i++)
    if (d[p] < d[i]) p = i;
  for (int i = 1; i <= tot; i++) d[i] = 0;
  dfs(p, 0);
  p = 0;
  for (int i = 1; i <= tot; i++) p = max(p, d[i]);
  printf("%d", p / 2);
}
