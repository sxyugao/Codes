#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int a[15], f[15][10][2];
int dp(int len, int lst, bool lim) {
    if (!len) return 1;
    if (~f[len][lst][lim]) return f[len][lst][lim];
    int mx = lim ? a[len] : 9;
    int ans = 0;
    for (int i = lst; i <= mx; i++)
        ans += dp(len - 1, i, lim && i == mx);
    return f[len][lst][lim] = ans;
}
int solve(int x) {
    memset(f, -1, sizeof(f));
    int len = 0;
    do {
        a[++len] = x % 10;
        x /= 10;
    } while (x);
    return dp(len, 0, 1);
}
int main() {
    int l, r;
    while (~scanf("%d%d", &l, &r)) {
        printf("%d\n", solve(r) - solve(l - 1));
    }
}