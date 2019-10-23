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
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
char obuf[1 << 14], *p = obuf;
inline void pc(char c) {
  if (obuf + (1 << 14) == p) {
    fwrite(obuf, 1, 1 << 14, stdout);
    p = obuf;
  }
  *p++ = c;
}
inline void fsh() {
  fwrite(obuf, 1, p - obuf, stdout);
}
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
const int N = 3e5 + 5;
const int K = 55;
const int P = 998244353;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int d[N], fa[N];
int top[N], son[N], siz[N];
void dfs1(int x, int f) {
  fa[x] = f;
  siz[x] = 1;
  d[x] = d[f] + 1;
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
int a[N][K];
void Add(int &x, int y) {
  x = x + y >= P ? x + y - P : x + y;
}
void dfs(int x) {
  int tmp = 1;
  for (int i = 1; i < K; i++) {
    tmp = 1LL * tmp * d[x] % P;
    Add(a[x][i], tmp);
    Add(a[x][i], a[fa[x]][i]);
  }
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa[x]) continue;
    dfs(y);
  }
}
int solve(int x, int y, int k) {
  int t = lca(x, y);
  return ((a[x][k] + a[y][k] - a[t][k] - a[fa[t]][k]) % P + P) % P;
}
int main() {
  int n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  d[0] = -1;
  dfs1(1, 0), dfs2(1, 1), dfs(1);
  for (int m = read(); m; m--) {
    int x = read(), y = read(), k = read();
    write(solve(x, y, k)), pc('\n');
  }
  fsh();
}
