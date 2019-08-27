#include <cstdio>
#include <cstring>
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
const int N = 1005;
int n, f[N][N];
int main() {
  while (n = read()) {
    int ans = f[1][1] = read();
    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= i; j++) {
        f[i][j] = f[i - 1][j] + f[i - 1][j - 1] - f[i - 2][j - 1] + read();
        ans = max(ans, f[i][j]);
      }
    writeln(ans);
  }
  fsh();
}
