#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
typedef map<LL, int>::iterator iter;
inline char _gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
inline LL read() {
  LL x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 1e6 + 5;
inline LL gcd(LL a, LL b) {
  while (b) {
    LL c = a % b;
    a = b, b = c;
  }
  return a;
}
int n;
LL ans, a[N];
map<LL, int> cnt;
inline void solve() {
  LL x = a[(rand() * RAND_MAX + rand()) % n + 1];
  cnt.clear();
  for (int i = 1; i <= n; i++) cnt[gcd(x, a[i])]++;
  iter i = cnt.end();
  do {
    --i;
    if (i->first <= ans) continue;
    int num = 0;
    for (iter j = i; j != cnt.end() && num * 2 < n; ++j)
      if (j->first % i->first == 0) num += j->second;
    if (num * 2 >= n) ans = i->first;
  } while (i != cnt.begin());
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= 10; i++) solve();
  printf("%lld", ans);
}
