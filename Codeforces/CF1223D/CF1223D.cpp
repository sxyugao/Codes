#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
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
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
const int N = 3e5 + 5;
int a[N];
struct Data {
  int l, r;
  void clear() { l = r = 0; }
} b[N];
inline void solve() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i].clear();
  a[n + 1] = 0;
  int num = 0;
  for (int i = 1, j; i <= n; i = j) {
    j = i;
    a[++num] = a[i];
    while (a[i] == a[j]) j++;
  }
  for (int i = 1; i <= num; i++) {
    if (!b[a[i]].l) b[a[i]].l = i;
    b[a[i]].r = i;
  }
  sort(a + 1, a + num + 1);
  int tot = 0;
  for (int i = 1, j; i <= num; i = j) {
    j = i;
    a[++tot] = a[i];
    while (a[i] == a[j]) j++;
  }
  int ans = tot, tmp = 0;
  for (int i = 1; i <= tot; i++) {
    if (b[a[i - 1]].r > b[a[i]].l) tmp = 0;
    tmp++;
    ans = min(ans, tot - tmp);
  }
  write(ans), pc('\n');
}
int main() {
  for (int T = read(); T; T--) solve();
  fsh();
}
