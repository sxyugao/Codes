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
typedef long long LL;
const int N = 5e4 + 5;
#define ls (k << 1)
#define rs (k << 1 | 1)
struct Data {
  LL lx, rx, sum, res;
  bool null;
  Data operator+(const Data &b) const {
    Data ans;
    if (null) return b;
    if (b.null) return *this;
    ans.lx = max(lx, sum + b.lx);
    ans.rx = max(b.rx, b.sum + rx);
    ans.sum = sum + b.sum;
    ans.res = max(res, b.res);
    ans.res = max(ans.res, rx + b.lx);
    ans.null = 0;
    return ans;
  }
};
struct Segtree {
  int l, r;
  Data x;
} tree[N << 2];
void pushup(int k) { tree[k].x = tree[ls].x + tree[rs].x; }
void build(int k, int l, int r) {
  tree[k].l = l, tree[k].r = r;
  if (l == r) {
    int v = read();
    tree[k].x.lx = tree[k].x.rx = v;
    tree[k].x.sum = tree[k].x.res = v;
    tree[k].x.null = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
void modify(int k, int l, int r, int v) {
  if (tree[k].l > r || tree[k].r < l) return;
  if (l <= tree[k].l && tree[k].r <= r) {
    tree[k].x.lx = tree[k].x.rx = v;
    tree[k].x.sum = tree[k].x.res = v;
    tree[k].x.null = 0;
    return;
  }
  modify(ls, l, r, v);
  modify(rs, l, r, v);
  pushup(k);
}
Data query(int k, int l, int r) {
  if (tree[k].l > r || tree[k].r < l) return Data{0, 0, 0, 0, 1};
  if (l <= tree[k].l && tree[k].r <= r) return tree[k].x;
  return query(ls, l, r) + query(rs, l, r);
}
#undef ls
#undef rs
int main() {
  int n = read();
  build(1, 1, n);
  for (int q = read(); q; q--) {
    int opt = read(), x = read(), y = read();
    if (opt == 0) modify(1, x, x, y);
    if (opt == 1) printf("%lld\n", query(1, x, y).res);
  }
}
