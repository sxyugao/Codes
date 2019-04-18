#include <cstdio>
#include <iostream>
using namespace std;
const int N = (1 << 12) + 5;
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
int n, m, opt;
long long tree[N][N];
int lowbit(int x) {
    return x & -x;
}
void add(int x, int y, int z) {
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j))
            tree[i][j] += z;
}
long long query(int x, int y) {
    long long ans = 0;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j))
            ans += tree[i][j];
    return ans;
}
int main() {
    n = read(), m = read();
    while (~scanf("%d", &opt)) {
        if (opt == 1) {
            int x = read(), y = read(), z = read();
            add(x, y, z);
        } else {
            int a = read(), b = read(), c = read(), d = read();
            printf("%lld\n", query(c, d) - query(a - 1, d) - query(c, b - 1) + query(a - 1, b - 1));
        }
    }
}