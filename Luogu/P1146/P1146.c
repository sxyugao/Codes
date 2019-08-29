#include <stdio.h>
int n, a[105];
int main() {
  scanf("%d", &n);
  printf("%d\n", n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      if (i ^ j) a[j] ^= 1;
    for (int j = 1; j <= n; j++) putchar('0' ^ a[j]);
    puts("");
  }
}