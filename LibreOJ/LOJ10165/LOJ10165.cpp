#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int l, r, a[20];
int f[20][10][2][2];
int dfs(int len, int lst, bool lim, bool zero) {
    if (!len) return !zero;
    if (~f[len][lst][lim][zero]) return f[len][lst][lim][zero];
    int mx = lim ? a[len] : 9;
    int ans = 0;
    for (int i = 0; i <= mx; i++) {
        if (!zero && (i == lst - 1 || i == lst || i == lst + 1)) continue;
        ans += dfs(len - 1, i, lim && i == mx, zero && i == 0);
    }
    return f[len][lst][lim][zero] = ans;
}
int solve(int x) {
    int len = 0;
    do {
        a[++len] = x % 10;
        x /= 10;
    } while (x);
    memset(f, -1, sizeof(f));
    return dfs(len, 0, 1, 1);
}
int main() {
    scanf("%d%d", &l, &r);
    printf("%d", solve(r) - solve(l - 1));
}