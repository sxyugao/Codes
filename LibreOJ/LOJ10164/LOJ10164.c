#include <stdbool.h>
#include <stdio.h>
int a[15], f[15][10][2];
int dp(int len, int lst, bool lim) {
    if (!len) return 1;
    int mx = lim ? a[len] : 9;
    int ans = 0;
    for (int i = lst; i <= mx; i++)
        ans += dp(len - 1, i, lim && i == mx);
    return ans;
}
int solve(int x) {
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