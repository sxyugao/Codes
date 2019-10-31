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
int a[N], b[N << 1];
int tot, T[N], v[N << 5], ls[N << 5], rs[N << 5];
void build(int lst, int &rt, int l, int r, int p, int x) {
  rt = ++tot;
  ls[rt] = ls[lst], rs[rt] = rs[lst];
  if (l == r) return void(v[rt] = x);
  int mid = (l + r) >> 1;
  if (p <= mid) build(ls[lst], ls[rt], l, mid, p, x);
  if (p > mid) build(rs[lst], rs[rt], mid + 1, r, p, x);
  v[rt] = min(v[ls[rt]], v[rs[rt]]);
}
int query(int rt, int l, int r, int x) {
  if (l == r) return b[l];
  int mid = (l + r) >> 1;
  if (v[ls[rt]] < x) return query(ls[rt], l, mid, x);
  return query(rs[rt], mid + 1, r, x);
}
int main() {
  int n = read(), m = read();
  b[++*b] = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    b[++*b] = a[i];
    b[++*b] = a[i] + 1;
  }
  sort(b + 1, b + *b + 1);
  *b = unique(b + 1, b + *b + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + *b + 1, a[i]) - b;
    build(T[i - 1], T[i], 1, *b, a[i], i);
  }
  while (m--) {
    int l = read(), r = read();
    write(query(T[r], 1, *b, l)), pc('\n');
  }
  fsh();
}
