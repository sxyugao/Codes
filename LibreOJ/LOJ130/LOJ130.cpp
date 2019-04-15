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
const int N = 1e6 + 5;
int n, m;
long long tree[N];
int lowbit(int x) { return x & -x; }
void add(int x, int v) {
    for (; x <= n; x += lowbit(x)) tree[x] += v;
}
long long sum(int x) {
    long long ans = 0;
    for (; x; x -= lowbit(x)) ans += tree[x];
    return ans;
}
int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) add(i, read());
    while (m--) {
        int opt = read(), x = read(), y = read();
        if (opt == 1) {
            add(x, y);
        } else {
            printf("%lld\n", sum(y) - sum(x - 1));
        }
    }
}