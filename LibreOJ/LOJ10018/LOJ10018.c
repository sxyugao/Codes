#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int n, m, f[205][10];
int main() {
    scanf("%d%d", &n, &m);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            for (int k = 1; k <= m; k++) f[j][k] += f[j - i][k - 1];
    printf("%d\n", f[n][m]);
}