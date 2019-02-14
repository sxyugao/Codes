#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n", ((a - 1) / b + 1) * b - a);
}
