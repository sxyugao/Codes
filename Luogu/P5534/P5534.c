#include <stdio.h>
long long a, b, d, n;
int main() {
  scanf("%lld%lld%lld", &a, &b, &n);
  d = b - a;
  printf("%lld", (2 * a + d * (n - 1)) * n / 2);
}