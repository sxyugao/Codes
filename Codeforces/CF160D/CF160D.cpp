#include <algorithm>
#include <cstdio>
#include <cstring>
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
const int MAXN = 2e5 + 5;
int nedge, head[MAXN];
struct Edge {
  int to, w, nxt, id;
} edge[MAXN << 1];
void add(int x, int y, int z, int id) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].id = id;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
struct E {
  int x, y, z, id;
  bool used;
  bool operator<(const E &b) const {
    return z < b.z;
  }
  void input() {
    x = read(), y = read(), z = read();
  }
} e[MAXN];
int d[MAXN], f[MAXN], siz[MAXN], son[MAXN], Id[MAXN];
int Find(int x) {
  return f[x] = f[x] == x ? x : Find(f[x]);
}
int w[MAXN];
void dfs1(int x, int fa) {
  f[x] = fa;
  siz[x] = 1;
  d[x] = d[fa] + 1;
  int Max = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    w[y] = edge[i].w;
    Id[y] = edge[i].id;
    dfs1(y, x);
    siz[x] += siz[y];
    if (siz[y] > Max) Max = siz[y], son[x] = y;
  }
}
int cnt, top[MAXN], id[MAXN], p[MAXN];
void dfs2(int x, int topf) {
  top[x] = topf;
  id[x] = ++cnt;
  p[cnt] = x;
  if (!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f[x] || y == son[x]) continue;
    dfs2(y, y);
  }
}
int ans[MAXN];
#define ls (k << 1)
#define rs (k << 1 | 1)
struct Segtree {
  int l, r, max;
} tree[MAXN << 2];
void pushup(int k) {
  tree[k].max = max(tree[ls].max, tree[rs].max);
}
void build(int k, int l, int r) {
  tree[k].l = l, tree[k].r = r;
  if (l == r) return (void)(tree[k].max = w[p[l]]);
  int mid = (l + r) >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(k);
}
int query(int k, int l, int r) {
  if (tree[k].l > r || tree[k].r < l) return 0;
  if (l <= tree[k].l && tree[k].r <= r) return tree[k].max;
  return max(query(ls, l, r), query(rs, l, r));
}
int query(int x, int y) {
  int ans = 0;
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    ans = max(ans, query(1, id[top[x]], id[x]));
    x = f[top[x]];
  }
  if (d[x] > d[y]) swap(x, y);
  return max(ans, query(1, id[x] + 1, id[y]));
}
void upd(int k, int l, int r, int v) {
  if (tree[k].max < v) return;
  if (tree[k].l > r || tree[k].r < l) return;
  if (tree[k].l == tree[k].r) return (void)(ans[Id[p[tree[k].l]]] = 2);
  upd(ls, l, r, v), upd(rs, l, r, v);
}
void upd(int x, int y, int v) {
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    upd(1, id[top[x]], id[x], v);
    x = f[top[x]];
  }
  if (d[x] > d[y]) swap(x, y);
  upd(1, id[x] + 1, id[y], v);
}
#undef ls
#undef rs
int main() {
  int n = read(), m = read(), Max = 0;
  for (int i = 1; i <= m; i++) e[i].input(), e[i].id = i;
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1, tot = 0; i <= m && tot < n; i++) {
    int x = Find(e[i].x), y = Find(e[i].y);
    if (x == y) continue;
    f[x] = y;
    tot++;
    e[i].used = 1;
    ans[e[i].id] = 1;
    Max = max(Max, e[i].z);
    add(e[i].x, e[i].y, e[i].z, e[i].id);
    add(e[i].y, e[i].x, e[i].z, e[i].id);
  }
  memset(f, 0, sizeof(f));
  dfs1(1, 0), dfs2(1, 1);
  build(1, 1, n);
  for (int i = 1; i <= m && e[i].z <= Max; i++)
    if (!e[i].used) {
      int Mx = query(e[i].x, e[i].y);
      if (Mx >= e[i].z) ans[e[i].id] = 2;
      upd(e[i].x, e[i].y, e[i].z);
    }
  for (int i = 1; i <= m; i++) {
    if (ans[i] == 0) puts("none");
    if (ans[i] == 1) puts("any");
    if (ans[i] == 2) puts("at least one");
  }
}
