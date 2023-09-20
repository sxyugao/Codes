#include <math.h>
#include <stdio.h>
#define PI 3.14
int r, h;
int main() {
  scanf("%d%d", &h, &r);
  printf("%d", (int)ceil(20000 / (PI * r * r * h)));
}