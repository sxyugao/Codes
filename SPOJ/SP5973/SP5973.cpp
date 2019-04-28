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
const int P = 1 << 23;
const int N = 1e5 + 5;
int f[N][30], pw[30];
void pre() {
    pw[0] = 1;
    for (int i = 1; i <= 23; i++) pw[i] = pw[i - 1] * 2 % P;
    f[0][0] = 1;
    for (int i = 1; i < N; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= min(i, 23); j++)
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % P;
    }
}
void Add(int &x, int y) {
    x = x + y >= P ? x + y - P : x + y;
}
int main() {
    pre();
    for (int T = read(); T; T--) {
        int n = read(), k = read();
        int ans = 0;
        for (int i = 1; i <= min(k, 23); i++)
            Add(ans, 1LL * f[n][i] * pw[i - 1] * i % P);
        printf("%d\n", ans);
    }
}