#include <stdio.h>
int n, t, ans;
double x;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf%d", &x, &t);
    for (int j = 1; j <= t; j++) ans ^= (int)(x * j);
  }
  printf("%d", ans);
}
