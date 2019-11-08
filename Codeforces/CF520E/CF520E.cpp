#include <cstdio>
#include <iostream>
using namespace std;
const int P = 1e9 + 7;
const int N = 1e5 + 5;
inline void Add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
inline int pw(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = 1LL * ans * a % P;
    a = 1LL * a * a % P;
    n >>= 1;
  }
  return ans;
}
int fac[N], inv[N];
inline int C(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return 1LL * fac[n] * inv[m] % P * inv[n - m] % P;
}
int n, k, ans, a[N], pw10[N];
int main() {
  scanf("%d%d\n", &n, &k);
  for (int i = 1; i <= n; i++) {
    char c = getchar();
    a[i] = a[i - 1];
    Add(a[i], c ^ '0');
  }
  fac[0] = pw10[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % P;
  for (int i = 1; i <= n; i++) pw10[i] = 1LL * pw10[i - 1] * 10 % P;
  inv[n] = pw(fac[n], P - 2);
  for (int i = n - 1; ~i; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % P;
  for (int i = 0; i < n; i++) {
    Add(ans, 1LL * a[n - i - 1] * pw10[i] % P * C(n - i - 2, k - 1) % P);
    Add(ans, 1LL * (a[n - i] - a[n - i - 1]) * pw10[i] % P * C(n - i - 1, k) % P);
  }
  printf("%d", ans);
}
