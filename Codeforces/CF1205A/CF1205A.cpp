#include <cstdio>
int n;
int main() {
  scanf("%d", &n);
  if (n % 2 == 0) return puts("NO"), 0;
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", 2 * i - (i & 1));
  for (int i = 1; i <= n; i++) printf("%d ", 2 * i - !(i & 1));
}
