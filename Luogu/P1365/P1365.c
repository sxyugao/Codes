#include <stdio.h>
double f[2], g[2];
int main() {
  int n;
  char c;
  scanf("%d\n", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%c", &c);
    int now = i & 1, lst = (i - 1) & 1;
    f[now] = f[lst];
    if (c == 'x') g[now] = 0;
    if (c == 'o') f[now] += 2 * g[lst] + 1, g[now] = g[lst] + 1;
    if (c == '?') f[now] += (2 * g[lst] + 1) / 2, g[now] = (g[lst] + 1) / 2;
  }
  printf("%.4lf", f[n & 1]);
}