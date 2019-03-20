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
const int N = 4e4 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int rt, fa[N], siz[N], son[N];
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
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    if (y < 0) {
      rt = x;
    } else {
      add(x, y), add(y, x);
    }
  }
  dfs1(rt, 0);
  dfs2(rt, rt);
  for (n = read(); n; n--) {
    int x = read(), y = read();
    int p = lca(x, y);
    if (p == x)
      puts("1");
    else if (p == y)
      puts("2");
    else
      puts("0");
  }
}