#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
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
const int MAXN = 100005;
int nedge, head[MAXN];
struct Edge {
  int to, nxt;
} edge[MAXN * 2];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int fa[MAXN], d[MAXN], siz[MAXN], son[MAXN];
int cnt, id[MAXN], a[MAXN], w[MAXN], top[MAXN];
void dfs1(int k, int f) {
  fa[k] = f;
  d[k] = d[f] + 1;
  siz[k] = 1;
  int Max = 0;
  for (int i = head[k]; i; i = edge[i].nxt) {
    int u = edge[i].to;
    if (u == f) continue;
    dfs1(u, k);
    if (siz[u] > Max) Max = siz[u], son[k] = u;
    siz[k] += siz[u];
  }
}
void dfs2(int k, int topf) {
  id[k] = ++cnt;
  a[cnt] = w[k];
  top[k] = topf;
  if (!son[k]) return;
  dfs2(son[k], topf);
  for (int i = head[k]; i; i = edge[i].nxt) {
    int u = edge[i].to;
    if (u == fa[k] || u == son[k]) continue;
    dfs2(u, u);
  }
}
#define ls (k << 1)
#define rs (k << 1 | 1)
struct Segtree {
  int l, r;
  LL x, lazy;
} tree[MAXN << 2];
void pushup(int k) { tree[k].x = tree[ls].x + tree[rs].x; }
void pushdown(int k) {
  if (tree[k].lazy == 0) return;
  tree[ls].lazy += tree[k].lazy;
  tree[rs].lazy += tree[k].lazy;
  tree[ls].x += tree[k].lazy * (tree[ls].r - tree[ls].l + 1);
  tree[rs].x += tree[k].lazy * (tree[rs].r - tree[rs].l + 1);
  tree[k].lazy = 0;
}
void build(int k, int l, int r) {
  tree[k].l = l;
  tree[k].r = r;
  if (l == r) return (void)(tree[k].x = a[l]);
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
void modify(int k, int l, int r, LL v) {
  if (tree[k].l > r || tree[k].r < l) return;
  if (l <= tree[k].l && tree[k].r <= r) {
    tree[k].lazy += v;
    tree[k].x += v * (tree[k].r - tree[k].l + 1);
    return;
  }
  pushdown(k);
  modify(ls, l, r, v);
  modify(rs, l, r, v);
  pushup(k);
}
LL query(int k, int l, int r) {
  if (tree[k].l > r || tree[k].r < l) return 0;
  if (l <= tree[k].l && tree[k].r <= r) return tree[k].x;
  pushdown(k);
  return query(ls, l, r) + query(rs, l, r);
}
#undef ls
#undef rs
LL query(int x, int y) {
  LL ans = 0;
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    ans += query(1, id[top[x]], id[x]);
    x = fa[top[x]];
  }
  if (d[x] > d[y]) swap(x, y);
  ans += query(1, id[x], id[y]);
  return ans;
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) w[i] = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
  }
  dfs1(1, 0), dfs2(1, 1);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int opt = read();
    if (opt == 1) {
      int x = read(), v = read();
      modify(1, id[x], id[x], v);
    }
    if (opt == 2) {
      int x = read(), v = read();
      modify(1, id[x], id[x] + siz[x] - 1, v);
    }
    if (opt == 3) printf("%lld\n", query(1, read()));
  }
}
