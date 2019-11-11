#include <stdio.h>
int n;
int main() {
  scanf("%d", &n);
  if (!n) return puts("1"), 0;
  n = n << 1 | 1;
  int ans = 1, x = 2;
  for (; x ^ 1; x = x * 2 % n) ans++;
  printf("%d", ans);
}
