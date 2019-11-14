#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 2e5 + 5;
#define ls (k << 1)
#define rs (k << 1 | 1)
struct Segtree {
  struct Data {
    int l, r;
    long long lazy;
    double cos, sin;
  } tree[N << 2];
  void pushup(int k) {
    tree[k].sin = tree[ls].sin + tree[rs].sin;
    tree[k].cos = tree[ls].cos + tree[rs].cos;
  }
  void update(int k, long long x) {
    double sinx = sin(x), cosx = cos(x);
    double siny = tree[k].sin, cosy = tree[k].cos;
    tree[k].sin = siny * cosx + cosy * sinx;
    tree[k].cos = cosy * cosx - siny * sinx;
  }
  void pushdown(int k) {
    if (!tree[k].lazy) return;
    update(ls, tree[k].lazy);
    update(rs, tree[k].lazy);
    tree[ls].lazy += tree[k].lazy;
    tree[rs].lazy += tree[k].lazy;
    tree[k].lazy = 0;
  }
  void build(int k, int l, int r) {
    tree[k].l = l, tree[k].r = r;
    if (l == r) {
      int x = read();
      tree[k].sin = sin(x);
      tree[k].cos = cos(x);
      return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(k);
  }
  void add(int k, int l, int r, int v) {
    if (tree[k].l > r || tree[k].r < l) return;
    if (l <= tree[k].l && tree[k].r <= r) {
      tree[k].lazy += v;
      update(k, v);
      return;
    }
    pushdown(k);
    add(ls, l, r, v), add(rs, l, r, v);
    pushup(k);
  }
  double query(int k, int l, int r) {
    if (tree[k].l > r || tree[k].r < l) return 0;
    if (l <= tree[k].l && tree[k].r <= r) return tree[k].sin;
    pushdown(k);
    return query(ls, l, r) + query(rs, l, r);
  }
} T;
#undef ls
#undef rs
int main() {
  int n = read();
  T.build(1, 1, n);
  for (int q = read(); q; q--) {
    int opt = read(), l = read(), r = read();
    if (opt == 1) T.add(1, l, r, read());
    if (opt == 2) printf("%.1lf\n", T.query(1, l, r));
  }
}
