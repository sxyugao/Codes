#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
inline int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 1e5 + 5;
const int P = 1e8 - 3;
int n, p[N], t[N];
struct Data {
  int x, p;
  bool operator<(const Data &b) const {
    return x < b.x;
  }
} a[N], b[N];
#define lowbit(x) (x & -x)
inline void add(int x) {
  for (; x <= n; x += lowbit(x)) t[x]++;
}
inline int query(int x) {
  int ans = 0;
  for (; x; x -= lowbit(x)) ans += t[x];
  return ans;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i].x = read(), a[i].p = i;
  for (int i = 1; i <= n; i++) b[i].x = read(), b[i].p = i;
  sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) p[a[i].p] = b[i].p;
  int ans = 0;
  for (int i = n; i; i--) {
    ans += query(p[i] - 1);
    if (ans >= P) ans -= P;
    add(p[i]);
  }
  printf("%d", ans);
}
