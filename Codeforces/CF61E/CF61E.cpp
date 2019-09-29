#include <algorithm>
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
const int N = 1e6 + 5;
int num, a[N], b[N], cnt[N];
#define lowbit(x) (x & -x)
struct Tree {
  int tree[N];
  void add(int x) {
    for (; x <= num; x += lowbit(x)) tree[x]++;
  }
  int query(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) ans += tree[x];
    return ans;
  }
} T1, T2;
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = b[i] = read();
  sort(b + 1, b + n + 1);
  num = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + num + 1, a[i]) - b;
  for (int i = 1; i <= n; i++) {
    cnt[i] = T1.query(num) - T1.query(a[i]);
    T1.add(a[i]);
  }
  long long ans = 0;
  for (int i = n; i; i--) {
    ans += 1LL * T2.query(a[i] - 1) * cnt[i];
    T2.add(a[i]);
  }
  printf("%lld", ans);
}
