#include <cstdio>
int gcd(int a, int b) {
  while (b) {
    int c = a % b;
    a = b, b = c;
  }
  return a;
}
int main() {
  int a, b, n, x = 0;
  scanf("%d%d%d", &a, &b, &n);
  while (n) {
    x ^= 1;
    n -= gcd(n, x ? a : b);
  }
  printf("%d", x ^ 1);
}
