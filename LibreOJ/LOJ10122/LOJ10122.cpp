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
const int N = 2e5 + 5;
int f[30][N];
int main() {
    int n = read();
    for (int i = 1; i <= n; i++) f[0][i] = read();
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 1; j + (1 << (i - 1)) - 1 <= n; j++)
            f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
    for (int m = read(); m; m--) {
        int l = read(), r = read();
        int k = log2(r - l + 1);
        printf("%d\n", max(f[k][l], f[k][r - (1 << k) + 1]));
    }
}