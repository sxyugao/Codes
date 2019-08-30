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
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
void writeln(int x) {
  write(x), pc('\n');
}
const int N = 5e5 + 5;
const int S = 707;
int a[N], sum[S + 3][S + 3];
int main() {
  for (int q = read(); q; q--) {
    int opt = read(), x = read(), y = read();
    if (opt == 1) {
      a[x] += y;
      for (int i = 1; i <= S; i++) sum[i][x % i] += y;
    } else {
      if (x <= S) {
        writeln(sum[x][y]);
      } else {
        int ans = 0;
        for (int i = y; i < N; i += x) ans += a[i];
        writeln(ans);
      }
    }
  }
  fsh();
}
