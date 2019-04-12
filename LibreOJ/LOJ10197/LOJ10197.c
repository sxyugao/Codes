#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define N 1000005
int pri[N], x[N];
bool vis[N];
int main() {
    int l, r, a, b, c, d;
    for (int i = 2; i <= N; i++) {
        if (vis[i]) continue;
        x[++x[0]] = i;
        for (int j = 2; i * j <= N - 5; j++) vis[i * j] = 1;
    }
    while (~scanf("%d%d", &l, &r)) {
        memset(vis, 0, sizeof(vis));
        a = -1e9, b = 1e9, c = 1e9, d = -1e9;
        for (int j = 1; j <= x[0] && x[j] <= r; j++) {
            for (int k = max(l / x[j], 2); 1LL * x[j] * k <= r; k++)
                if (1LL * x[j] * k >= l) vis[x[j] * k - l] = 1;
        }
        pri[0] = 0;
        for (unsigned i = l; i <= r; i++) {
            if (i == 1 || vis[i - l]) continue;
            pri[++pri[0]] = i;
            if (pri[0] < 2) continue;
            int del = pri[pri[0]] - pri[pri[0] - 1];
            if (del < b - a) {
                b = pri[pri[0]];
                a = pri[pri[0] - 1];
            }
            if (del > d - c) {
                d = pri[pri[0]];
                c = pri[pri[0] - 1];
            }
        }
        if (pri[0] < 2) {
            puts("There are no adjacent primes.");
        } else {
            printf("%d,%d are closest, %d,%d are most distant.\n", a, b, c, d);
        }
    }
}