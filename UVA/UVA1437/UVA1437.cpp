#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 105;
int n, g[N], f[N][N];
char a[N], b[N];
int main() {
  while (gets(a + 1) && gets(b + 1)) {
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    n = strlen(a + 1);
    for (int i = n; i; i--) {
      f[i][i] = 1;
      for (int j = i + 1; j <= n; j++) {
        f[i][j] = f[i][j - 1] + 1;
        for (int k = i; k < j; k++)
          if (b[k] == b[j]) f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j - 1]);
      }
    }
    for (int i = 1; i <= n; i++) {
      g[i] = f[1][i];
      if (a[i] == b[i]) g[i] = min(g[i], g[i - 1]);
      for (int j = 1; j < i; j++)
        g[i] = min(g[i], g[j] + f[j + 1][i]);
    }
    printf("%d\n", g[n]);
  }
}
