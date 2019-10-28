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
const int N = 2e5 + 5;
int a[N], st[N], ed[N], fa[N];
int main() {
  int n = read(), m = read(), k = read();
  int mn = 0, mx = 1;
  for (int i = 1; i <= m; i++) {
    a[i] = read();
    mn = max(mn, a[i]);
    mx += a[i] - 1;
  }
  if (k < mn || k > mx) return puts("-1"), 0;
  st[0] = ed[0] = 1, a[0] = 1;
  for (int i = 1; i <= m; i++) st[i] = ed[i - 1] + 1, ed[i] = st[i] + a[i] - 1;
  for (int i = 1; i <= m; i++)
    for (int j = st[i]; j <= ed[i]; j++) fa[j] = st[i - 1];
  int p1 = st[2] + 1, x1 = 2, p2 = st[1] + 1, x2 = 1;
  while (mx > k) {
    bool f;
    do {
      f = 0;
      while (p2 > ed[x2]) {
        x2++, p2 = st[x2] + 1;
        if (x2 > m) return puts("-1"), 0;
      }
      while (x1 <= x2 || p1 > ed[x1]) {
        x1++, p1 = st[x1] + 1;
        if (x1 > m) return puts("-1"), 0;
      }
      if (x2 + 1 != x1 || p2 > ed[x2]) {
        x2++, p2 = st[x2] + 1, f = 1;
        if (x2 > m) return puts("-1"), 0;
      }
    } while (f);
    fa[p1] = p2;
    p1++, p2++;
    mx--;
  }
  write(n), pc('\n');
  for (int i = 2; i <= n; i++) write(fa[i]), pc(' '), write(i), pc('\n');
  fsh();
}
