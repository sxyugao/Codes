#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 2005;
int d[N], f[N], a[N][N];
bool vis[N];
int main() {
  int n = read(), m = read();
  memset(a, 0x3f, sizeof(a));
  while (m--) {
    int x = read(), y = read();
    a[x][y] = min(a[x][y], read());
  }
  memset(d, 0x3f, sizeof(d));
  d[1] = 0, f[1] = 1;
  for (int i = 1; i <= n; i++) {
    int p = 0;
    for (int j = 1; j <= n; j++)
      if (d[j] < d[p] && !vis[j]) p = j;
    vis[p] = 1;
    for (int j = 1; j <= n; j++) {
      if (d[p] + a[p][j] == d[j]) f[j] += f[p];
      if (d[p] + a[p][j] < d[j]) {
        d[j] = d[p] + a[p][j];
        f[j] = f[p];
      }
    }
  }
  if (d[n] > 1e9) return puts("No answer"), 0;
  printf("%d %d", d[n], f[n]);
}
