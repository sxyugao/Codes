#include <stdio.h>
int a, b, c, d, e, f;
int main() {
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  printf("%d\n", (a * b + c * d + e * f) / 10);
}
