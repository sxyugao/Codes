#include <stdio.h>
int a, b, c, d;
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  printf("%.12lf", 1.0 * a / b / (1 - (1 - 1.0 * a / b) * (1 - 1.0 * c / d)));
}
