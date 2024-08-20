#include <stdio.h>
int phi(int x) {
  int tmp = x, res = 1;
  for (int i = 2; i * i <= tmp; ++i) {
    if (tmp % i) continue;
    res *= i - 1;
    tmp /= i;
    while (tmp % i == 0) res *= i, tmp /= i;
  }
  if (tmp > 1) res *= tmp - 1;
  return res;
}
int pw(int a, int n, int P) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1LL * res * a % P;
    a = 1LL * a * a % P;
    n >>= 1;
  }
  return res;
}
int dfs(int a, int P) {
  if (a == 2023) return a;
  return pw(a, dfs(a + 1, phi(P)) + phi(P), P);
}
int main() { printf("%d", dfs(2, 2023)); }