#include <iostream>
typedef long long LL;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline LL read() {
  LL x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
const LL N = 1414215;
LL pre[N], pre_sum[N];
LL sum(LL p) {
  LL l = 0, r = N, mid = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (pre[mid] >= p) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (r < 0) r = 0;
  return pre_sum[r] + pre[p - pre[r]];
}
int main() {
  for (int i = 1; i < N; ++i) {
    pre[i] = pre[i - 1] + i;
    pre_sum[i] = pre_sum[i - 1] + pre[i];
  }
  for (int T = read(); T; --T) {
    LL l = read(), r = read();
    printf("%lld\n", sum(r) - sum(l - 1));
  }
}
