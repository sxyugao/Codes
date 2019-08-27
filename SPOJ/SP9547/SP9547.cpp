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
char buf[1 << 14], *p = buf;
void pc(char c) {
  if (buf + (1 << 14) == p) {
    fwrite(buf, 1, 1 << 14, stdout);
    p = buf;
  }
  *p++ = c;
}
void fsh() {
  fwrite(buf, 1, p - buf, stdout);
}
void write(long long x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
void writeln(long long x) {
  write(x), pc('\n');
}
const int N = 1e6 + 5;
long long a[N];
int b[N], lst[N];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  int p = 1;
  for (int i = 1; i <= n; i++) {
    if (lst[b[i]] >= p) p = lst[b[i]] + 1;
    lst[b[i]] = i;
    a[1]++, a[i - p + 2]--;
  }
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  for (int q = read(); q; q--) {
    int l = read(), r = read();
    writeln(a[r] - a[l - 1]);
  }
  fsh();
}
