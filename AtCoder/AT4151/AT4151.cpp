#include <cstdio>
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d", (b - a) * (b - a - 1) / 2 - a);
}