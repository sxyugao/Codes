#include <ctype.h>
#include <stdio.h>
char buf[1 << 14], *p1 = buf, *p2 = buf;
char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
#define N 20005
int l[N], r[N], f[N][2];
int min(int a, int b) { return a < b ? a : b; }
int abs(int x) { return x > 0 ? x : -x; }
int main() {
  int n = read();
  l[0] = r[0] = 1;
  l[n + 1] = r[n + 1] = n;
  for (int i = 1; i <= n; ++i) l[i] = read(), r[i] = read();
  for (int i = 1; i <= n + 1; ++i) {
    f[i][0] = min(f[i - 1][0] + abs(l[i - 1] - r[i]),
                  f[i - 1][1] + abs(r[i - 1] - r[i]));
    f[i][1] = min(f[i - 1][0] + abs(l[i - 1] - l[i]),
                  f[i - 1][1] + abs(r[i - 1] - l[i]));
    f[i][0] += r[i] - l[i];
    f[i][1] += r[i] - l[i];
  }
  printf("%d", f[n + 1][0] + n - 1);
}