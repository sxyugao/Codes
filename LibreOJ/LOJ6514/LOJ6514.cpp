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
int d[N], f[20][N];
int tot, l[N], r[N];
void dfs(int x, int fa) {
  l[x] = ++tot;
  d[x] = d[fa] + 1;
  f[0][x] = fa;
  for (int i = 1; (1 << i) <= d[x]; i++)
    f[i][x] = f[i - 1][f[i - 1][x]];
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y ^ fa) dfs(y, x);
  }
  r[x] = tot;
}
inline bool isIn(int rt, int x) {
  if (!rt) return 1;
  return l[rt] <= l[x] && r[x] <= r[rt];
}
inline int lca(int x, int y) {
  if (isIn(x, y)) return x;
  for (int i = 19; ~i; i--)
    if (!isIn(f[i][x], y)) x = f[i][x];
  return f[0][x];
}
int n, m, q, p[N];
struct Data {
  int l, r;
  bool operator<(const Data &b) const {
    return l < b.l;
  }
} a[N];
inline int jump(int x, int step) {
  for (int i = 0; step; i++, step >>= 1)
    if (step & 1) x = f[i][x];
  return x;
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
  dfs(1, 0);
  while (q--) {
    m = read();
    for (int i = 1; i <= m; i++) p[i] = read();
    write(n - solve()), pc('\n');
  }
  fsh();
}
