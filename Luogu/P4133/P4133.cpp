#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
const int N = 90;
LL n, g[N + 5] = {0, 1, 2};
map<LL, int> f[N + 5];
int dfs(LL n, int k) {
    if (!n) return 1;
    if (!k) return 0;
    if (f[k].count(n)) return f[k][n];
    int ans = 0;
    if (g[k] <= n) ans += dfs(n - g[k], k - 1);
    if (n < g[k + 1]) ans += dfs(n, k - 1);
    return f[k][n] = ans;
}
int main() {
    for (int i = 3; i <= N + 1; i++) g[i] = g[i - 1] + g[i - 2];
    scanf("%lld", &n);
    printf("%d", dfs(n, N));
}