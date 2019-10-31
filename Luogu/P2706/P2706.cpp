#include <cstdio>
#include <iostream>
using namespace std;
const int N = 305;
int n, m, a[N][N], sum[N][N];
int l[N][N], r[N][N], up[N][N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }
  for (int i = 1; i <= n; i++) {
    int p = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) l[i][j] = p + 1;
      if (!a[i][j]) p = j;
    }
  }
  for (int i = 1; i <= n; i++) {
    int p = m + 1;
    for (int j = m; j; j--) {
      if (a[i][j]) r[i][j] = p - 1;
      if (!a[i][j]) r[i][j] = m + 1, p = j;
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) r[0][i] = m + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        l[i][j] = max(l[i][j], l[i - 1][j]);
        r[i][j] = min(r[i][j], r[i - 1][j]);
        up[i][j] = up[i - 1][j];
        int L = l[i][j], R = r[i][j], p = up[i][j];
        ans = max(ans, sum[i][R] - sum[i][L - 1] - sum[p][R] + sum[p][L - 1]);
      }
      if (!a[i][j]) up[i][j] = i;
    }
  }
  printf("%d", ans);
}
