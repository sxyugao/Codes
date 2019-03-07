#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
#define gc c = getchar()
ull read() {
  ull x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 1e5 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int n, m, k;
int dep[N], fa[N], son[N], siz[N];
void dfs1(int x, int f) {
  fa[x] = f;
  siz[x] = 1;
  dep[x] = dep[f] + 1;
  int mx = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs1(y, x);
    siz[x] += siz[y];
    if (siz[y] > mx) {
      mx = siz[y];
      son[x] = y;
    }
  }
}
int tot, id[N], p[N], top[N];
void dfs2(int x, int topf) {
  top[x] = topf;
  id[x] = ++tot;
  p[tot] = x;
  if (!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa[x] || y == son[x]) continue;
    dfs2(y, y);
  }
}
struct Data {
  ull x0, x1;
  Data() { x0 = 0, x1 = ~0; }
  Data(int opt, ull x) {
    x0 = 0, x1 = ~0;
    if (opt == 1) {
      x0 &= x;
      x1 &= x;
    }
    if (opt == 2) {
      x0 |= x;
      x1 |= x;
    }
    if (opt == 3) {
      x0 ^= x;
      x1 ^= x;
    }
  }
  Data operator+(const Data &b) const {
    Data ans;
    ans.x0 = (x0 & b.x1) | ((~x0) & b.x0);
    ans.x1 = (x1 & b.x1) | ((~x1) & b.x0);
    return ans;
  }
  ull query(ull x) {
    ull ans = 0;
    for (int i = k - 1; ~i; i--) {
      if (x0 & (1ull << i)) {
        ans += (1ull << i);
      } else if (x1 & (1ull << i) && (1ull << i) <= x) {
        x -= (1ull << i);
        ans += (1ull << i);
      }
    }
    return ans;
  }
};
Data a[N];
#define ls (k << 1)
#define rs (k << 1 | 1)
struct Segtree {
  Data lv[N << 2], rv[N << 2];
  void pushup(int k) {
    lv[k] = lv[ls] + lv[rs];
    rv[k] = rv[rs] + rv[ls];
  }
  void build(int k, int l, int r) {
    if (l == r) {
      lv[k] = rv[k] = a[p[l]];
      return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(k);
  }
  void modify(int k, int l, int r, int p, Data x) {
    if (l == r) return (void)(lv[k] = rv[k] = x);
    int mid = (l + r) >> 1;
    if (p <= mid) {
      modify(ls, l, mid, p, x);
    } else {
      modify(rs, mid + 1, r, p, x);
    }
    pushup(k);
  }
  Data query(int k, int l, int r, int ql, int qr, bool opt) {
    if (ql <= l && r <= qr) return opt ? rv[k] : lv[k];
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(ls, l, mid, ql, qr, opt);
    if (ql > mid) return query(rs, mid + 1, r, ql, qr, opt);
    Data L = query(ls, l, mid, ql, qr, opt);
    Data R = query(rs, mid + 1, r, ql, qr, opt);
    if (opt) return R + L;
    return L + R;
  }
} seg;
#undef ls
#undef rs
Data query(int x, int y) {
  Data L, R;
  while (top[x] ^ top[y]) {
    if (dep[top[x]] > dep[top[y]]) {
      L = L + seg.query(1, 1, n, id[top[x]], id[x], 1);
      x = fa[top[x]];
    } else {
      R = seg.query(1, 1, n, id[top[y]], id[y], 0) + R;
      y = fa[top[y]];
    }
  }
  Data tmp;
  if (dep[x] > dep[y]) {
    tmp = L + seg.query(1, 1, n, id[y], id[x], 1);
    tmp = tmp + R;
    return tmp;
  }
  if (dep[x] > dep[y]) return L + seg.query(1, 1, n, id[y], id[x], 1) + R;
  return L + seg.query(1, 1, n, id[x], id[y], 0) + R;
}
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) {
    int opt = read();
    ull x = read();
    a[i] = Data(opt, x);
  }
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs1(1, 0), dfs2(1, 1);
  seg.build(1, 1, n);
  while (m--) {
    int opt = read(), x = read(), y = read();
    ull z = read();
    if (opt == 2) {
      seg.modify(1, 1, n, id[x], Data(y, z));
    } else {
      Data ans = query(x, y);
      printf("%llu\n", ans.query(z));
    }
  }
}