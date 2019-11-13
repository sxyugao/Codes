#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
char obuf[1 << 14], *_p = obuf;
inline void pc(char c) {
  if (obuf + (1 << 14) == _p) {
    fwrite(obuf, 1, 1 << 14, stdout);
    _p = obuf;
  }
  *_p++ = c;
}
inline void fsh() {
  fwrite(obuf, 1, _p - obuf, stdout);
}
void write(int x) {
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
const int N = 5e5 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
inline void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int d[N], fa[N], siz[N], son[N];
void dfs1(int x, int f) {
  fa[x] = f;
  d[x] = d[f] + 1;
  siz[x] = 1;
  int mx = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs1(y, x);
    siz[x] += siz[y];
    if (siz[y] > mx) mx = siz[y], son[x] = y;
  }
}
int tot, top[N], l[N], r[N], id[N];
void dfs2(int x, int topf) {
  l[x] = ++tot;
  id[tot] = x;
  top[x] = topf;
  if (son[x]) dfs2(son[x], topf);
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa[x] || y == son[x]) continue;
    dfs2(y, y);
  }
  r[x] = tot;
}
inline int lca(int x, int y) {
  while (top[x] ^ top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return d[x] < d[y] ? x : y;
}
int n, m, q, p[N];
struct Data {
  int l, r;
  bool operator<(const Data &b) const {
    return l < b.l;
  }
} a[N];
inline int jump(int x, int step) {
  int dep = d[x] - step;
  while (dep < d[top[x]]) x = fa[top[x]];
  return id[l[x] - d[x] + dep];
}
inline int solve() {
  int num = 0;
  for (int i = 2; i <= m; i++) {
    int LCA = lca(p[1], p[i]);
    int dis = (d[p[1]] + d[p[i]] - 2 * d[LCA] - 1) / 2;
    if (d[p[i]] - d[LCA] > dis) {
      int x = jump(p[i], dis);
      a[++num] = {l[x], r[x]};
    } else {
      int x = jump(p[1], d[p[1]] + d[p[i]] - 2 * d[LCA] - dis - 1);
      if (l[x] > 1) a[++num] = {1, l[x] - 1};
      if (r[x] < n) a[++num] = {r[x] + 1, n};
    }
  }
  sort(a + 1, a + num + 1);
  int ans = 0, pos = 0;
  for (int i = 1; i <= num; i++)
    if (a[i].l <= pos) {
      if (a[i].r > pos) ans += a[i].r - pos, pos = a[i].r;
    } else {
      ans += a[i].r - a[i].l + 1;
      pos = a[i].r;
    }
  return ans;
}
int main() {
  n = read(), q = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs1(1, 0), dfs2(1, 1);
  while (q--) {
    m = read();
    for (int i = 1; i <= m; i++) p[i] = read();
    write(n - solve()), pc('\n');
  }
  fsh();
}
