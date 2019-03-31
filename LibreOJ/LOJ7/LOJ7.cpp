#include <cstdio>
#include <iostream>
using namespace std;
inline char _gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
#define gc c = _gc()
inline bool read(long long &x) {
  x = 0;
  int f = 1;
  char gc;
  for (; !isdigit(c); gc) {
    if (c == '-') f = -1;
    if (c == EOF) return 0;
  }
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  x *= f;
  return 1;
}
#undef gc
int main() {
  long long ans = 0, x;
  while (read(x)) ans ^= x;
  printf("%lld", ans);
}