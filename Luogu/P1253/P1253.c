#include <ctype.h>
#include <stdio.h>
typedef long long LL;
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
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
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
void write(LL x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
void writeln(LL x) { write(x), pc('\n'); }
#define N 1000005
int a[N];
struct Segtree {
  LL mx, addTag;
  int coverTag, hasCoverTag;
} tree[N << 2];
#define lson (now << 1)
#define rson (now << 1 | 1)
LL max(LL a, LL b) { return a > b ? a : b; }
void pushup(int now) { tree[now].mx = max(tree[lson].mx, tree[rson].mx); }
void pushdown(int now) {
  if (tree[now].hasCoverTag) {
    tree[lson].addTag = tree[rson].addTag = 0;
    tree[lson].hasCoverTag = tree[rson].hasCoverTag = 1;
    tree[lson].coverTag = tree[rson].coverTag = tree[now].coverTag;
    tree[lson].mx = tree[rson].mx = tree[now].coverTag;
    tree[now].hasCoverTag = 0;
  }
  if (tree[now].addTag) {
    tree[lson].mx += tree[now].addTag;
    tree[rson].mx += tree[now].addTag;
    tree[lson].addTag += tree[now].addTag;
    tree[rson].addTag += tree[now].addTag;
    tree[now].addTag = 0;
  }
}
void build(int now, int l, int r) {
  tree[now].hasCoverTag = 0;
  tree[now].coverTag = 0;
  tree[now].addTag = 0;
  if (l == r) return (void)(tree[now].mx = a[l]);
  int mid = (l + r) >> 1;
  build(lson, l, mid);
  build(rson, mid + 1, r);
  pushup(now);
}
void upd_cover(int now, int l, int r, int tl, int tr, int x) {
  if (l > tr || r < tl) return;
  if (tl <= l && r <= tr) {
    tree[now].hasCoverTag = 1;
    tree[now].coverTag = x;
    tree[now].mx = x;
    tree[now].addTag = 0;
    return;
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  upd_cover(lson, l, mid, tl, tr, x);
  upd_cover(rson, mid + 1, r, tl, tr, x);
  pushup(now);
}
void upd_add(int now, int l, int r, int tl, int tr, int x) {
  if (l > tr || r < tl) return;
  if (tl <= l && r <= tr) {
    tree[now].addTag += x;
    tree[now].mx += x;
    return;
  }
  pushdown(now);
  int mid = (l + r) >> 1;
  upd_add(lson, l, mid, tl, tr, x);
  upd_add(rson, mid + 1, r, tl, tr, x);
  pushup(now);
}
LL query(int now, int l, int r, int tl, int tr) {
  if (tl <= l && r <= tr) return tree[now].mx;
  if (l > tr || r < tl) return -1e18;
  pushdown(now);
  int mid = (l + r) >> 1;
  LL res = -1e18;
  res = max(res, query(lson, l, mid, tl, tr));
  res = max(res, query(rson, mid + 1, r, tl, tr));
  pushup(now);
  return res;
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  build(1, 1, n);
  while (m--) {
    int op = read(), l = read(), r = read();
    if (op == 3) {
      writeln(query(1, 1, n, l, r));
      continue;
    }
    int x = read();
    if (op == 1)
      upd_cover(1, 1, n, l, r, x);
    else
      upd_add(1, 1, n, l, r, x);
  }
  fsh();
}