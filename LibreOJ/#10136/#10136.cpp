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
const int N = 5e5 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int fa[N], siz[N], son[N];
void dfs1(int x, int f) {
  fa[x] = f;
  siz[x] = 1;
  int mx = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs1(y, x);
    siz[x] += siz[y];
    if (siz[y] > mx) {
      mx = siz[y];
      son[x] = y;
    }
  }
}
int top[N], d[N];
void dfs2(int x, int topf) {
  top[x] = topf;
  d[x] = d[fa[x]] + 1;
  if (!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa[x] || y == son[x]) continue;
    dfs2(y, y);
  }
}
int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return d[x] < d[y] ? x : y;
}
int dis(int x, int y) { return d[x] + d[y] - 2 * d[lca(x, y)]; }
int main() {
  int n = read(), m = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  while (m--) {
    int a = read(), b = read(), c = read();
    int lca1 = lca(a, b), lca2 = lca(b, c), lca3 = lca(a, c);
    if (lca1 == lca2)
      printf("%d %d\n", lca3, dis(a, lca3) + dis(b, lca3) + dis(c, lca3));
    else if (lca1 == lca3)
      printf("%d %d\n", lca2, dis(a, lca2) + dis(b, lca2) + dis(c, lca2));
    else if (lca2 == lca3)
      printf("%d %d\n", lca1, dis(a, lca1) + dis(b, lca1) + dis(c, lca1));
  }
}