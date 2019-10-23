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
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int w, h, d[N], fa[N], cnt[N];
int top[N], son[N], siz[N];
void dfs1(int x, int f) {
  fa[x] = f;
  siz[x] = 1;
  d[x] = d[f] + 1;
  cnt[d[x]]++;
  h = max(h, d[x]);
  w = max(w, cnt[d[x]]);
  int mx = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs1(y, x);
    siz[x] += siz[y];
    if (siz[y] > mx) mx = siz[y], son[x] = y;
  }
}
void dfs2(int x, int topf) {
  top[x] = topf;
  if (!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa[x] || y == son[x]) continue;
    dfs2(y, y);
  }
}
int lca(int x, int y) {
  while (top[x] ^ top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return d[x] < d[y] ? x : y;
}
int main() {
  int n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs1(1, 0), dfs2(1, 1);
  int u = read(), v = read();
  printf("%d\n%d\n%d", h, w, d[u] * 2 + d[v] - d[lca(u, v)] * 3);
}
