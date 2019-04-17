#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
inline char _gc() {
    static char buf[1 << 26], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 26, stdin), p1 == p2) ? EOF : *p1++;
}
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
char obuf[1 << 26], *p = obuf;
inline void pc(const char &c) {
    if (p - obuf == (1 << 26)) {
        fwrite(obuf, 1, 1 << 26, stdout);
        p = obuf;
    }
    *p++ = c;
}
void fsh() {
    fwrite(obuf, 1, p - obuf, stdout);
}
void write(int x) {
    if (x < 0) pc('-'), x = -x;
    if (x > 9) write(x / 10);
    pc(x % 10 ^ '0');
}
void writeln(int x) {
    write(x);
    pc('\n');
}
const int N = 5e5 + 5;
int n, m;
int lowbit(int x) {
    return x & -x;
}
struct Tree {
    int tree[N];
    void add(int x) {
        for (; x <= n; x += lowbit(x)) tree[x]++;
    }
    int query(int x) {
        int ans = 0;
        for (; x > 0; x -= lowbit(x)) ans += tree[x];
        return ans;
    }
} t1, t2;
int num;
struct Segment {
    int l, r, len;
    void input() {
        l = read(), r = read();
        len = r - l;
    }
    bool operator<(const Segment &b) const {
        return len < b.len;
    }
} a[N];
struct Ask {
    int l, r, k, opt, id;
    bool operator<(const Ask &b) const {
        return k < b.k;
    }
} q[N << 1];
int ans[N];
int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i].input();
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read(), k = read();
        if (k > r - l) continue;
        q[++num] = {l, r, k - 1, -1, i};
        q[++num] = {l, r, r - l, 1, i};
    }
    sort(q + 1, q + num + 1);
    for (int i = 1, j = 1; i <= num; i++) {
        for (; j <= n && a[j].len <= q[i].k; j++) {
            t1.add(a[j].l);
            t2.add(a[j].r);
        }
        ans[q[i].id] += q[i].opt * (t2.query(q[i].r) - t1.query(q[i].l - 1));
    }
    for (int i = 1; i <= m; i++) writeln(ans[i]);
    fsh();
}