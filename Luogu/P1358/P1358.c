#include <stdio.h>
#define N 10005
const int P = 10007;
int fac[N], inv[N];
int pw(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = res * a % P;
    a = a * a % P;
    n >>= 1;
  }
  return res;
}
int C(int n, int m) { return fac[n] * inv[m] % P * inv[n - m] % P; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % P;
  inv[n] = pw(fac[n], P - 2);
  for (int i = n - 1; ~i; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % P;
  int ans = 1, x;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &x);
    ans = ans * C(n, x) % P;
    n -= x;
  }
  printf("%d", ans);
}