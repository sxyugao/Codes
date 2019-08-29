#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
inline char _gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
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
const int N = 3e5 + 5;
int a[N], b[N];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i < n; i++) b[i] = a[i + 1] - a[i];
  sort(b + 1, b + n);
  long long ans = 0;
  for (int i = 1; i <= n - m; i++) ans += b[i];
  printf("%lld", ans);
}