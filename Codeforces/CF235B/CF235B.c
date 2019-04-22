#include <stdio.h>
double x, f[2], g[2];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &x);
    int now = i & 1, lst = (i - 1) & 1;
    g[now] = (g[lst] + 1) * x;
    f[now] = f[lst] + (2 * g[lst] + 1) * x;
  }
  printf("%.15lf", f[n & 1]);
}