#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n, a = 1;
  long long b = 1;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) a *= i, b *= 2 * n - i - 1;
  printf("%d", b / a);
}