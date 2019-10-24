#include <stdio.h>
long long n, p, x, y;
int a, b;
int main() {
  scanf("%lld%lld%d%d", &n, &p, &a, &b);
  while (y < a && (p - 1LL * b * y) % a) y++;
  if (y == a) return puts("-1"), 0;
  x = (p - 1LL * b * y) / a;
  if (x < 0 || x + y > n) return puts("-1"), 0;
  printf("%lld %lld %lld", x, y, n - x - y);
}
