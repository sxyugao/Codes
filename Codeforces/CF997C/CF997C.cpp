#include <cstdio>
const int N = 1e6 + 5;
const int P = 998244353;
int n, fac[N], inv[N];
inline int pw(int a, long long n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = 1LL * ans * a % P;
    a = 1LL * a * a % P;
    n >>= 1;
  }
  return ans;
}
inline int C(int n, int m) {
  return 1LL * fac[n] * inv[n - m] % P * inv[m] % P;
}
inline int add(int x, int y) {
  return (x += y) >= P ? x -= P : x;
}
inline int del(int x, int y) {
  return (x -= y) < 0 ? x += P : x;
}
int main() {
  scanf("%d", &n);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % P;
  inv[n] = pw(fac[n], P - 2);
  for (int i = n - 1; ~i; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % P;
  int ans = del(pw(3, 1LL * n * n), pw(del(pw(3, n), 3), n));
  for (int i = 1; i <= n; i++) {
    int a = 3LL * pw(pw(3, n - i) - 1, n) % P;
    int b = 1LL * del(pw(3, i), 3) * pw(3, 1LL * n * (n - i)) % P;
    int x = 1LL * C(n, i) * add(a, b) % P;
    ans = i & 1 ? add(ans, x) : ans = del(ans, x);
  }
  printf("%d", ans);
}
