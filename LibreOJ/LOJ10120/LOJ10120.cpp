#include <cmath>
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
const int N = 1e5 + 5;
int n, m, f[30][N], g[30][N];
int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) f[0][i] = g[0][i] = read();
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 1; j + (1 << (i - 1)) <= n; j++) {
            f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
            g[i][j] = min(g[i - 1][j], g[i - 1][j + (1 << (i - 1))]);
        }
    int k = log2(m);
    for (int i = 1; i <= n - m + 1; i++) {
        int mx = max(f[k][i], f[k][i + m - (1 << k)]);
        int mn = min(g[k][i], g[k][i + m - (1 << k)]);
        printf("%d %d\n", mx, mn);
    }
}