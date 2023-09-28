#include <stdio.h>
double m, h, bmi;
int main() {
  scanf("%lf%lf", &m, &h);
  bmi = m / h / h;
  if (bmi < 18.5) return puts("Underweight"), 0;
  if (bmi < 24) return puts("Normal"), 0;
  printf("%6g\nOverweight", bmi);
}