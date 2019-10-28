#include <algorithm>
#include <cstdio>
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
const int N = 1e5 + 5;
struct Data {
  int p, opt;
  bool operator<(const Data &b) const {
    return p < b.p;
  }
} a[N * 3];
int main() {
  int n = read();
  int num = 0;
  for (int i = 1; i <= n; i++) {
    int l = read(), r = read();
    a[++num] = {l, 1};
    a[++num] = {r, 0};
    a[++num] = {r + 1, -1};
  }
  sort(a + 1, a + num + 1);
  int cnt = 0;
  long long ans = 0;
  for (int i = 1; i <= num; i++) {
    cnt += a[i].opt;
    ans = max(ans, 1LL * cnt * a[i].p);
  }
  printf("%lld", ans);
}
