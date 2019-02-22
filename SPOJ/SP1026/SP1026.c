#include <stdio.h>
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    double ans = 0;
    for (int i = 1; i <= n; i++) ans += 1.0 * n / (n - i + 1);
    printf("%.2lf\n", ans);
  }
}