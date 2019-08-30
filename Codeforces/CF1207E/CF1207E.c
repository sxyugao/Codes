#include <stdio.h>
int x, ans;
int main() {
  putchar('?');
  for (int i = 1; i <= 100; i++) printf(" %d", i);
  puts("");
  fflush(stdout);
  scanf("%d", &x);
  ans = x >> 7 << 7;
  putchar('?');
  for (int i = 1; i <= 100; i++) printf(" %d", i << 7);
  puts("");
  fflush(stdout);
  scanf("%d", &x);
  printf("! %d", ans + (127 & x));
}
