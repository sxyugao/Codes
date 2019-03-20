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
const int N = 1e4 + 5;
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
int fa[N], siz[N], son[N], dep[N], d[N];
void dfs1(int x, int f) {
  fa[x] = f;
  siz[x] = 1;
  dep[x] = dep[f] + 1;
  int mx = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f) continue;
    d[y] = d[x] + edge[i].w;
    dfs1(y, x);
    siz[x] += siz[y];
    if (siz[y] > mx) {
      mx = siz[y];
      son[x] = y;
    }
  }
}
int top[N];
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
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read(), z = read();
    add(x, y, z), add(y, x, z);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  while (m--) {
    int x = read(), y = read();
    printf("%d\n", d[x] + d[y] - 2 * d[lca(x, y)]);
  }
}