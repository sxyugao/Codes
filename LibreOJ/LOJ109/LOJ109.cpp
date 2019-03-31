#include <cstdio>
#include <iostream>
using namespace std;
const int N = 4000000;
const int P = 998244353;
inline char _gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
#define gc c = _gc()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
int f[N + 5], rk[N + 5];
int Find(int x) { return f[x] = x == f[x] ? x : Find(f[x]); }
long long ans;
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) f[i] = i;
  for (n = read(); n; n--) {
    int opt = read(), x = read(), y = read();
    x = Find(x), y = Find(y);
    if (opt) {
      ans = ans << 1 | (x == y);
      ans %= P;
    } else {
      if (rk[x] < rk[y]) {
        f[x] = y;
      } else {
        f[y] = x;
        if (rk[x] == rk[y]) rk[x]++;
      }
    }
  }
  printf("%lld", ans);
}