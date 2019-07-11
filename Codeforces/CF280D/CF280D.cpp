#include <cstdio>
#include <iostream>
using namespace std;
inline char _gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
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
struct Data {
  int lmx, rmx, lmxp, rmxp, mxl, mxr;
  int lmn, rmn, lmnp, rmnp, mnl, mnr;
  int mx, mn, sum;
  void upd() {
    sum *= -1, mx *= -1, mn *= -1;
    lmx *= -1, rmx *= -1, lmn *= -1, rmn *= -1;
    swap(mx, mn);
    swap(mxl, mnl), swap(mxr, mnr);
    swap(lmx, lmn), swap(rmx, rmn);
    swap(lmxp, lmnp), swap(rmxp, rmnp);
  }
  Data operator+(const Data &b) const {
    Data ans;
    ans.sum = sum + b.sum;
    if (lmx > sum + b.lmx) {
      ans.lmx = lmx;
      ans.lmxp = lmxp;
    } else {
      ans.lmx = sum + b.lmx;
      ans.lmxp = b.lmxp;
    }
    if (b.rmx > rmx + b.sum) {
      ans.rmx = b.rmx;
      ans.rmxp = b.rmxp;
    } else {
      ans.rmx = rmx + b.sum;
      ans.rmxp = rmxp;
    }
    if (mx > b.mx) {
      ans.mx = mx;
      ans.mxl = mxl, ans.mxr = mxr;
    } else {
      ans.mx = b.mx;
      ans.mxl = b.mxl, ans.mxr = b.mxr;
    }
    if (rmx + b.lmx > ans.mx) {
      ans.mx = rmx + b.lmx;
      ans.mxl = rmxp, ans.mxr = b.lmxp;
    }

    if (lmn < sum + b.lmn) {
      ans.lmn = lmn;
      ans.lmnp = lmnp;
    } else {
      ans.lmn = sum + b.lmn;
      ans.lmnp = b.lmnp;
    }
    if (b.rmn < rmn + b.sum) {
      ans.rmn = b.rmn;
      ans.rmnp = b.rmnp;
    } else {
      ans.rmn = rmn + b.sum;
      ans.rmnp = rmnp;
    }
    if (mn < b.mn) {
      ans.mn = mn;
      ans.mnl = mnl, ans.mnr = mnr;
    } else {
      ans.mn = b.mn;
      ans.mnl = b.mnl, ans.mnr = b.mnr;
    }
    if (rmn + b.lmn < ans.mn) {
      ans.mn = rmn + b.lmn;
      ans.mnl = rmnp, ans.mnr = b.lmnp;
    }
    return ans;
  }
};
#define ls (k << 1)
#define rs (k << 1 | 1)
struct Segtree {
  Data a[N << 2];
  bool lazy[N << 2];
  void pushup(int k) {
    a[k] = a[ls] + a[rs];
  }
  void pushdown(int k) {
    if (!lazy[k]) return;
    lazy[k] = 0;
    lazy[ls] ^= 1;
    lazy[rs] ^= 1;
    a[ls].upd(), a[rs].upd();
  }
  void build(int k, int l, int r) {
    if (l == r) {
      int v = read();
      a[k].lmx = a[k].rmx = v;
      a[k].lmxp = a[k].rmxp = a[k].mxl = a[k].mxr = l;
      a[k].lmn = a[k].rmn = v;
      a[k].lmnp = a[k].rmnp = a[k].mnl = a[k].mnr = l;
      a[k].mx = a[k].mn = a[k].sum = v;
      return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(k);
  }
  void modify(int k, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
      a[k].lmx = a[k].rmx = v;
      a[k].lmn = a[k].rmn = v;
      a[k].mx = a[k].mn = a[k].sum = v;
      return;
    }
    pushdown(k);
    int mid = (l + r) >> 1;
    if (qr <= mid)
      modify(ls, l, mid, ql, qr, v);
    else if (ql > mid)
      modify(rs, mid + 1, r, ql, qr, v);
    else {
      modify(ls, l, mid, ql, qr, v);
      modify(rs, mid + 1, r, ql, qr, v);
    }
    pushup(k);
  }
  void update(int k, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return (void)(a[k].upd(), lazy[k] ^= 1);
    pushdown(k);
    int mid = (l + r) >> 1;
    if (qr <= mid)
      update(ls, l, mid, ql, qr);
    else if (ql > mid)
      update(rs, mid + 1, r, ql, qr);
    else {
      update(ls, l, mid, ql, qr);
      update(rs, mid + 1, r, ql, qr);
    }
    pushup(k);
  }
  Data query(int k, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return a[k];
    int mid = (l + r) >> 1;
    pushdown(k);
    if (qr <= mid)
      return query(ls, l, mid, ql, qr);
    else if (ql > mid)
      return query(rs, mid + 1, r, ql, qr);
    return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
  }
} T;
#undef ls
#undef rs
int vx[N], vy[N];
int main() {
  int n = read();
  T.build(1, 1, n);
  for (int m = read(); m; m--) {
    int opt = read(), x = read(), y = read();
    if (opt == 0) T.modify(1, 1, n, x, x, y);
    if (opt == 1) {
      int k = read();
      int ans = 0, now = 0;
      for (int i = 1; i <= k; i++) {
        Data tmp = T.query(1, 1, n, x, y);
        now += tmp.mx;
        ans = max(ans, now);
        vx[i] = tmp.mxl, vy[i] = tmp.mxr;
        T.update(1, 1, n, vx[i], vy[i]);
      }
      printf("%d\n", ans);
      for (int i = k; i; i--) T.update(1, 1, n, vx[i], vy[i]);
    }
  }
}
