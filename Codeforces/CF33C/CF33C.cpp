#include <cstdio>
#include <iostream>
using namespace std;
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
char obuf[1 << 14], *p = obuf;
inline void pc(char c) {
  if (obuf + (1 << 14) == p) {
    fwrite(obuf, 1, 1 << 14, stdout);
    p = obuf;
  }
  *p++ = c;
}
inline void fsh() {
  fwrite(obuf, 1, p - obuf, stdout);
}
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
const int N = 1e5 + 5;
int a[N], l[N], r[N];
int main() {
  int n = read();
  int sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i] = read();
  for (int i = 1; i <= n; i++) l[i] = l[i - 1] - a[i] * 2;
  for (int i = 1; i <= n; i++) l[i] = max(l[i], l[i - 1]);
  for (int i = n; i >= 1; i--) r[i] = r[i + 1] - a[i] * 2;
  for (int i = n; i >= 1; i--) r[i] = max(r[i], r[i + 1]);
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, sum + l[i] + r[i + 1]);
  write(ans);
  fsh();
}
