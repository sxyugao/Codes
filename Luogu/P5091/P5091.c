#include <ctype.h>
#include <stdio.h>
int pw(int a, int n, int P) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1LL * res * a % P;
    a = 1LL * a * a % P;
    n >>= 1;
  }
  return res;
}
int main() {
  int a, P;
  scanf("%d%d", &a, &P);
  int tmp = P, phi = 1;
  for (int i = 2; i * i <= tmp; ++i) {
    if (tmp % i) continue;
    phi *= i - 1;
    tmp /= i;
    while (tmp % i == 0) phi *= i, tmp /= i;
  }
  if (tmp > 1) phi *= tmp - 1;
  char c = getchar();
  int b = 0, f = 0;
  for (c = getchar(); isdigit(c); c = getchar()) {
    b = 1LL * b * 10 + c - '0';
    if (b >= phi) {
      f = 1;
      b %= phi;
    }
  }
  b += f * phi;
  printf("%d", pw(a, b, P));
}