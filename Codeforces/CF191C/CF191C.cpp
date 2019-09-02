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
const int N = 1e5 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt, id;
} edge[N << 1];
void add(int x, int y, int id) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  edge[nedge].id = id;
  head[x] = nedge;
}
int d[N], fa[N], son[N], siz[N];
int p[N], id[N];
void dfs1(int x, int f) {
  siz[x] = 1;
  fa[x] = f;
  d[x] = d[f] + 1;
  int mx = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs1(y, x);
    siz[x] += siz[y];
    p[y] = edge[i].id;
    if (siz[y] > mx) mx = siz[y], son[x] = y;
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
  while (top[x] ^ top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return d[x] < d[y] ? x : y;
}
int a[N], ans[N];
void dfs(int x) {
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa[x]) continue;
    dfs(y);
    a[x] += a[y];
  }
}
int main() {
  int n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y, i), add(y, x, i);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  for (int k = read(); k; k--) {
    int x = read(), y = read();
    a[x]++, a[y]++;
    a[lca(x, y)] -= 2;
  }
  dfs(1);
  for (int i = 1; i <= n; i++) ans[p[i]] = a[i];
  for (int i = 1; i < n; i++) printf("%d ", ans[i]);
}
