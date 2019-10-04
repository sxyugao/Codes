#include <stdio.h>
int a, b, c;
int main() {
  while (scanf("%d%d%d", &a, &b, &c), a || b || c)
    if (2 * b == a + c)
      printf("AP %d\n", c + b - a);
    else
      printf("GP %d\n", c * b / a);
}