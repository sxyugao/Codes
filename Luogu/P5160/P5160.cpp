#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline char _gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
#define gc c = _gc()
inline LL read() {
  LL x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int P = 19491001;
int fac[P], inv[P];
int C(LL n, LL m) {
  if (n > m) return 0;
  if (n < P && m < P) return 1LL * fac[m] * inv[n] % P * inv[m - n] % P;
  return 1LL * C(n / P, m / P) * C(n % P, m % P) % P;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i < P; i++) fac[i] = 1LL * fac[i - 1] * i % P;
  inv[P - 1] = P - 1;
  for (int i = P - 2; ~i; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % P;
  for (int T = read(); T; T--) {
    LL n = read(), m = read();
    printf("%d\n", C(n, n + m));
  }
}