#include <ctype.h>
#include <stdio.h>
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
char gc() {
  return p1 == p2 &&
                 (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
char obuf[1 << 14], *p = obuf;
void pc(char c) {
  if (obuf + (1 << 14) == p) {
    fwrite(obuf, 1, 1 << 14, stdout);
    p = obuf;
  }
  *p++ = c;
}
void fsh() { fwrite(obuf, 1, p - obuf, stdout); }
void write(int x) {
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
#define N 100005
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
int f[N];
int Find(int x) { return f[x] = f[x] == x ? x : Find(f[x]); }
int d[N];
void dfs(int x, int f, int sum) {
  d[x] = sum;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs(y, x, sum ^ edge[i].w);
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
  dfs(1, 0, 0);
  while (q--) {
    int x = read(), y = read();
    write(d[x] ^ d[y]), pc('\n');
  }
  fsh();
}
