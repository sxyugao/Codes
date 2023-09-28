#include <ctype.h>
#include <stdio.h>
char buf[1 << 14], *p1 = buf, *p2 = buf;
char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
#define N 50005
int n, a, b, nedge, d[N], head[N], siz[N], to[N << 1], nxt[N << 1];
void add(int x, int y) {
  to[++nedge] = y;
  nxt[nedge] = head[x];
  head[x] = nedge;
}
int tot, f[N];
void dfs1(int x, int fa) {
  d[x] = d[fa] + 1;
  tot += d[x];
  siz[x] = 1;
  for (int i = head[x]; i; i = nxt[i])
    if (to[i] != fa) {
      dfs1(to[i], x);
      siz[x] += siz[to[i]];
    }
}
void dfs2(int x, int fa) {
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y != fa) {
      f[y] = f[x] - siz[y] + (n - siz[y]);
      dfs2(y, x);
    }
  }
}
int main() {
  n = read();
  for (int i = 1; i < n; ++i) {
    a = read(), b = read();
    add(a, b), add(b, a);
  }
  d[0] = -1;
  dfs1(1, 0);
  f[1] = tot;
  dfs2(1, 0);
  int ans = 1, tot = f[1];
  for (int i = 2; i <= n; ++i)
    if (f[i] < tot) {
      tot = f[i], ans = i;
    }
  printf("%d %d", ans, tot);
}