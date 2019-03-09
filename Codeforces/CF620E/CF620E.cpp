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
const int N = 4e5 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int tot, id[N], p[N], siz[N];
void dfs(int x, int f) {
  siz[x] = 1;
  id[x] = ++tot, p[tot] = x;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs(y, x);
    siz[x] += siz[y];
  }
}
int c[N];
struct Segtree {
  int l, r;
  long long v, lazy;
} tree[N << 2];
#define ls (k << 1)
#define rs (k << 1 | 1)
void pushup(int k) { tree[k].v = tree[ls].v | tree[rs].v; }
void pushdown(int k) {
  if (!tree[k].lazy) return;
  tree[ls].v = tree[ls].lazy = tree[k].lazy;
  tree[rs].v = tree[rs].lazy = tree[k].lazy;
  tree[k].lazy = 0;
}
void build(int k, int l, int r) {
  tree[k].l = l, tree[k].r = r;
  if (l == r) return (void)(tree[k].v = 1LL << (c[p[l]] - 1));
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
void modify(int k, int l, int r, int c) {
  if (tree[k].l > r || tree[k].r < l) return;
  if (l <= tree[k].l && tree[k].r <= r) {
    tree[k].v = 1LL << (c - 1);
    tree[k].lazy = 1LL << (c - 1);
    return;
  }
  pushdown(k);
  modify(ls, l, r, c);
  modify(rs, l, r, c);
  pushup(k);
}
long long query(int k, int l, int r) {
  if (tree[k].l > r || tree[k].r < l) return 0;
  if (l <= tree[k].l && tree[k].r <= r) return tree[k].v;
  pushdown(k);
  return query(ls, l, r) | query(rs, l, r);
}
#undef ls
#undef rs
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) c[i] = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  build(1, 1, n);
  while (m--) {
    int opt = read(), rt = read();
    if (opt == 1) {
      modify(1, id[rt], id[rt] + siz[rt] - 1, read());
    } else {
      int ans = __builtin_popcountll(query(1, id[rt], id[rt] + siz[rt] - 1));
      printf("%d\n", ans);
    }
  }
}