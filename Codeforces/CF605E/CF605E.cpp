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
const int N = 1005;
#define ls (k << 1)
#define rs (k << 1 | 1)
struct Segtree {
    double mn[N << 2];
    int p[N << 2];
    void pushup(int k) {
        mn[k] = min(mn[ls], mn[rs]);
        if (mn[k] == mn[ls]) {
            p[k] = p[ls];
        } else {
            p[k] = p[rs];
        }
    }
    void build(int k, int l, int r) {
        if (l == r) return (void)(mn[k] = 1e18, p[k] = l);
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(k);
    }
    void modify(int k, int l, int r, int pos, double v) {
        if (l > pos || r < pos) return;
        if (l == r) return (void)(mn[k] = v);
        int mid = (l + r) >> 1;
        modify(ls, l, mid, pos, v);
        modify(rs, mid + 1, r, pos, v);
        pushup(k);
    }
    int query() { return p[1]; }
} seg;
#undef ls
#undef rs
double a[N][N], f[N], g[N], p[N];
bool vis[N];
int main() {
    int n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[j][i] = 1.0 * read() / 100;
    for (int i = 1; i < n; i++) f[i] = 1e18;
    seg.build(1, 1, n);
    seg.modify(1, 1, n, n, 0);
    for (int i = 1; i <= n; i++) {
        int x = seg.query();
        seg.modify(1, 1, n, x, 1e18);
        vis[x] = 1;
        for (int y = 1; y <= n; y++) {
            if (vis[y]) continue;
            if (a[x][y] == 0) continue;
            double tmp = (1 - p[y]) * a[x][y];
            g[y] += f[x] * tmp;
            p[y] += tmp;
            f[y] = (g[y] + 1) / p[y];
            seg.modify(1, 1, n, y, f[y]);
        }
    }
    printf("%.15lf", f[1]);
}