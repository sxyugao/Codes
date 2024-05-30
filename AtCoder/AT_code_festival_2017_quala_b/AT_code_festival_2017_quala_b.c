#include <stdio.h>
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      if (n * j + m * i - 2 * i * j == k) return puts("Yes"), 0;
  puts("No");
}