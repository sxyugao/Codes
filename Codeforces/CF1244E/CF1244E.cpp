#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
inline char gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
template <class T>
inline bool read(T &x) {
  x = 0;
  bool f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc()) {
    if (c == '-') f ^= 1;
    if (c == -1) return -1;
  }
  for (; isdigit(c); c = gc()) x = x * 10 + (c ^ 48);
  x = f ? x : -x;
  return 1;
}
const int N = 1e5 + 5;
int n, a[N], b[N], cnt[N];
long long k;
int main() {
  read(n), read(k);
  for (int i = 1; i <= n; i++) read(a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) b[i] = a[i];
  int num = unique(a + 1, a + n + 1) - a - 1;
  for (int i = 1; i <= n; i++) {
    int p = lower_bound(a + 1, a + num + 1, b[i]) - a;
    cnt[p]++;
  }
  int l = 1, r = num;
  bool f = 1;
  while (l < r && f) {
    f = 0;
    if (cnt[l] < cnt[r]) {
      long long tmp = 1LL * (a[l + 1] - a[l]) * cnt[l];
      if (k >= tmp) {
        f = 1;
        k -= tmp;
        cnt[l + 1] += cnt[l];
        l++;
      }
    } else {
      long long tmp = 1LL * (a[r] - a[r - 1]) * cnt[r];
      if (k >= tmp) {
        f = 1;
        k -= tmp;
        cnt[r - 1] += cnt[r];
        r--;
      }
    }
  }
  printf("%d\n", max(0LL, a[r] - a[l] - k / min(cnt[l], cnt[r])));
}
