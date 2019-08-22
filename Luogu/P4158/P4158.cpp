#include <cstdio>
#include <iostream>
using namespace std;
const int N = 55;
int n, m, T;
int F[N], f[N][N * N], g[2][N][N];
char a[N][N];
int main() {
  scanf("%d%d%d\n", &n, &m, &T);
  for (int i = 1; i <= n; i++) gets(a[i] + 1);
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= m; i++) {
      int x1 = a[k][i] == '0', x2 = a[k][i] == '1';
      for (int j = 1; j <= min(i, T); j++) {
        g[0][i][j] = max(g[0][i - 1][j], g[1][i - 1][j - 1]) + x1;
        g[1][i][j] = max(g[1][i - 1][j], g[0][i - 1][j - 1]) + x2;
      }
    }
    for (int i = 1; i <= m; i++) F[i] = max(g[0][m][i], g[1][m][i]);
    for (int i = 1; i <= T; i++)
      for (int j = 0; j <= i && j <= m; j++)
        f[k][i] = max(f[k][i], f[k - 1][i - j] + F[j]);
  }
  printf("%d", f[n][T]);
}
