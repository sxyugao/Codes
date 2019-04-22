#include <stdio.h>
double f[2], x1[2], x2[2];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    double x;
    scanf("%lf", &x);
    int now = i & 1, lst = (i - 1) & 1;
    x1[now] = (x1[lst] + 1) * x;
    x2[now] = (x2[lst] + 2 * x1[lst] + 1) * x;
    f[now] = f[lst] + (3 * x2[lst] + 3 * x1[lst] + 1) * x;
  }
  printf("%.1lf", f[n & 1]);
}