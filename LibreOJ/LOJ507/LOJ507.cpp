#include <cstdio>
#include <iostream>
using namespace std;
inline char gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 1e6 + 5;
int c[N];
long long a[N], f[N], g[N];
int main() {
  int n = read(), k = read();
  for (int i = 1; i <= n; i++) c[i] = read();
  for (int i = 1; i <= n; i++) a[i] = a[i - 1] + read();
  for (int i = 1; i <= k; i++) g[i] = -1e18;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1];
    f[i] = max(g[c[i]] + a[i], f[i]);
    g[c[i]] = max(g[c[i]], f[i - 1] - a[i - 1]);
  }
  printf("%lld", f[n]);
}
