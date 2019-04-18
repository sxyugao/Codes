#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
inline char _gc() {
    static char buf[1 << 14], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
LL read() {
    LL x = 0, f = 1;
    char gc;
    for (; !isdigit(c); gc)
        if (c == '-') f = -1;
    for (; isdigit(c); gc) x = x * 10 + c - '0';
    return x * f;
}
#undef gc
const int N = 2e4 + 5;
LL f[N];
struct Data {
    int a, b;
    void input() {
        a = read(), b = read();
    }
    bool operator<(const Data &c) const {
        int x = min(a, c.b), y = min(b, c.a);
        if (x == y) return a < c.a;
        return x < y;
    }
} p[N];
int main() {
    for (int T = read(); T; T--) {
        int n = read();
        for (int i = 1; i <= n; i++) p[i].input();
        sort(p + 1, p + n + 1);
        LL sum = f[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum += p[i].a;
            f[i] = max(f[i - 1], sum) + p[i].b;
        }
        printf("%lld\n", f[n]);
    }
}