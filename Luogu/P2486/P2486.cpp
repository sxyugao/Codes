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
int fa[N], siz[N], son[N], d[N];
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
  int lc, rc, sum;
  Data() { lc = rc = sum = 0; }
  Data(int c) {
    lc = rc = c;
    sum = 1;
  }
  bool operator==(const Data &b) const {
    return lc == b.lc && rc == b.rc && sum == b.sum;
  }
  Data rev() {
    Data ans = *this;
    swap(ans.lc, ans.rc);
    return ans;
  }
  Data operator+(const Data &b) const {
    if (*this == Data()) return b;
    if (b == Data()) return *this;
    Data ans;
    ans.sum = sum + b.sum;
    ans.sum -= rc == b.lc;
    ans.lc = lc;
    ans.rc = b.rc;
    return ans;
  }
};
int c[N];
struct Segtree {
  int l, r, lazy;
  Data x;
} tree[N << 2];
#define ls (k << 1)
#define rs (k << 1 | 1)
void pushup(int k) { tree[k].x = tree[ls].x + tree[rs].x; }
void pushdown(int k) {
  if (!tree[k].lazy) return;
  tree[ls].x = tree[rs].x = Data(tree[k].lazy);
  tree[ls].lazy = tree[rs].lazy = tree[k].lazy;
  tree[k].lazy = 0;
}
void build(int k, int l, int r) {
  tree[k].l = l, tree[k].r = r;
  if (l == r) return (void)(tree[k].x = Data(c[p[l]]));
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
void modify(int k, int l, int r, int v) {
  if (tree[k].l > r || tree[k].r < l) return;
  if (l <= tree[k].l && tree[k].r <= r) {
    tree[k].x = Data(v);
    tree[k].lazy = v;
    return;
  }
  pushdown(k);
  modify(ls, l, r, v);
  modify(rs, l, r, v);
  pushup(k);
}
Data query(int k, int l, int r) {
  if (tree[k].l > r || tree[k].r < l) return Data();
  if (l <= tree[k].l && tree[k].r <= r) return tree[k].x;
  pushdown(k);
  return query(ls, l, r) + query(rs, l, r);
}
#undef ls
#undef rs
void modify(int x, int y, int v) {
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    modify(1, id[top[x]], id[x], v);
    x = fa[top[x]];
  }
  if (d[x] > d[y]) {
    modify(1, id[y], id[x], v);
  } else {
    modify(1, id[x], id[y], v);
  }
}
int query(int x, int y) {
  Data ans, tmp;
  while (top[x] != top[y]) {
    if (d[top[x]] > d[top[y]]) {
      ans = ans + query(1, id[top[x]], id[x]).rev();
      x = fa[top[x]];
    } else {
      tmp = query(1, id[top[y]], id[y]) + tmp;
      y = fa[top[y]];
    }
  }
  if (d[x] > d[y]) {
    ans = ans + query(1, id[y], id[x]).rev();
  } else {
    tmp = query(1, id[x], id[y]) + tmp;
  }
  return (ans + tmp).sum;
}
char opt[10];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) c[i] = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs1(1, 0), dfs2(1, 1);
  build(1, 1, n);
  while (m--) {
    scanf("%s", opt);
    int x = read(), y = read();
    if (*opt == 'Q') {
      printf("%d\n", query(x, y));
    } else {
      modify(x, y, read());
    }
  }
}