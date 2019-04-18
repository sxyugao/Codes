#include <cstdio>
#include <iostream>
#include <queue>
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
const int N = 2e5 + 5;
int a[N], fa[N];
priority_queue<int> q[N];
int num, tmp[N];
void merge(int x, int y) {
    num = 0;
    while (q[x].size() && q[y].size()) {
        tmp[++num] = max(q[x].top(), q[y].top());
        q[x].pop(), q[y].pop();
    }
    if (q[y].size()) swap(q[x], q[y]);
    for (int i = 1; i <= num; i++) q[x].push(tmp[i]);
}
int main() {
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 2; i <= n; i++) fa[i] = read();
    for (int i = n; i > 1; i--) {
        q[i].push(a[i]);
        merge(fa[i], i);
    }
    long long ans = a[1];
    while (!q[1].empty()) {
        ans += q[1].top();
        q[1].pop();
    }
    printf("%lld", ans);
}