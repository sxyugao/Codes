#include <cmath>
#include <iostream>
using namespace std;
const double Pi = acos(-1);
int n, r;
double x;
int main() {
  scanf("%d%d", &n, &r);
  x = sin(Pi / n);
  printf("%.7lf", r * x / (1 - x));
}
