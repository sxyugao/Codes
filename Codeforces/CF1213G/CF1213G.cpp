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
const int N = 2e5 + 5;
struct Edge {
  int x, y, z;
  void input() {
    x = read(), y = read(), z = read();
  }
  bool operator<(const Edge &b) const {
    return z < b.z;
  }
} e[N];
struct Ask {
  int q, id;
  bool operator<(const Ask &b) const {
    return q < b.q;
  }
} ask[N];
int f[N], siz[N];
int Find(int x) {
  if (f[x] == x) return x;
  return f[x] = Find(f[x]);
}
long long ans[N];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
  for (int i = 1; i < n; i++) e[i].input();
  sort(e + 1, e + n);
  for (int i = 1; i <= m; i++) ask[i].q = read(), ask[i].id = i;
  sort(ask + 1, ask + m + 1);
  long long cnt = 0;
  int p = 1;
  for (int i = 1; i <= m; i++) {
    while (p < n && e[p].z <= ask[i].q) {
      int x = Find(e[p].x), y = Find(e[p].y);
      cnt += 1LL * siz[x] * siz[y];
      f[x] = y;
      siz[y] += siz[x];
      p++;
    }
    ans[ask[i].id] = cnt;
  }
  for (int i = 1; i <= m; i++) write(ans[i]), pc(' ');
  fsh();
}
