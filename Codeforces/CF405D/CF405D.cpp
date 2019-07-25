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
#define pc putchar
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
void writeln(int x) {
  write(x), pc('\n');
}
const int N = 1e6 + 5;
bool vis[N], sol[N];
int a[N], num, v[N], cnt, tmp[N];
int main() {
  int S = 1e6, n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    vis[a[i]] = 1;
  }
  n = 0;
  for (int i = 1; i <= S; i++)
    if (vis[i]) a[++n] = i;
  for (int i = 1; i <= n; i++)
    if (!vis[S - a[i] + 1]) {
      v[++num] = S - a[i] + 1;
      vis[S - a[i] + 1] = 1;
      sol[a[i]] = 1;
    }
  for (int i = 1; i <= S / 2; i++)
    if (!vis[i] && !vis[S - i + 1]) tmp[++cnt] = i;
  for (int i = 1; i <= n; i++)
    if (!sol[a[i]]) {
      v[++num] = tmp[cnt];
      v[++num] = S - tmp[cnt] + 1;
      cnt--;
      sol[a[i]] = 1;
      sol[S - a[i] + 1] = 1;
    }
  writeln(num);
  for (int i = 1; i <= num; i++) write(v[i]), pc(' ');
}
