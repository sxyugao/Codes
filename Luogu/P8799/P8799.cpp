#include <iostream>
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 2e5 + 5;
bool vis[N], ans[N];
int main() {
  int n = read(), m = read(), mx = 0;
  for (int i = 0; i < n; ++i) {
    int x = read();
    ans[1] |= vis[x];
    vis[x] = 1;
    if (x > mx) mx = x;
  }
  for (int x = 1; x <= mx / 2; ++x) {
    if (!vis[x]) continue;
    for (int q = 2; x * q <= mx; ++q) ans[q] |= vis[x * q];
  }
  while (m--) puts(ans[read()] ? "YES" : "NO");
}