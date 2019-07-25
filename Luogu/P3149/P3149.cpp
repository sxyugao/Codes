#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
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
void write(LL x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
void writeln(LL x) {
  write(x), pc('\n');
}
const int N = 3e5 + 5;
int n, m, a[N], b[N];
LL tree[N], c[N];
int lowbit(int x) { return x & -x; }
void add(int x) {
  for (; x <= n; x += lowbit(x)) tree[x]++;
}
LL query(int x) {
  LL ans = 0;
  for (; x; x -= lowbit(x)) ans += tree[x];
  return ans;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = b[i] = read();
  sort(b + 1, b + n + 1);
  int num = unique(b + 1, b + n + 1) - b - 1;
  b[num + 1] = 2e9;
  LL ans = 0;
  for (int i = n; i; i--) {
    int x = lower_bound(b + 1, b + num + 1, a[i]) - b;
    LL tmp = query(x);
    c[x] += tmp;
    ans += tmp;
    add(x);
  }
  writeln(ans);
  int lst = 1;
  while (m--) {
    int k = read();
    for (; b[lst] <= a[k]; lst++) ans -= c[lst];
    writeln(ans);
  }
}
