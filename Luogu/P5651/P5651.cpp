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
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
const int N = 1e5 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt, w;
} edge[N << 1];
inline void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int f[N];
int Find(int x) {
  return f[x] = f[x] == x ? x : Find(f[x]);
}
int d[N], dep[N], son[N], fa[N], siz[N];
void dfs1(int x, int f, int sum) {
  d[x] = sum;
  fa[x] = f;
  dep[x] = dep[f] + 1;
  siz[x] = 1;
  int mx = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs1(y, x, sum ^ edge[i].w);
    siz[x] += siz[y];
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
int main() {
  int n = read(), m = read(), q = read();
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    int tx = Find(x), ty = Find(y);
    if (tx ^ ty) {
      f[tx] = ty;
      add(x, y, z), add(y, x, z);
    }
  }
  dfs1(1, 0, 0), dfs2(1, 1);
  while (q--) {
    int x = read(), y = read();
    write(d[x] ^ d[y]), pc('\n');
  }
  fsh();
}
